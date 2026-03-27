#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStringList>
#include "company.h"
#include "companyforprofit.h"
#include "companynotforprofit.h"
#include "filereader.h"
#include "filewriter.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    list = new CompanyList;

    // get data previously saved from file
    FileReader reader;
    reader.read("backup.txt", list);
    updateDisplay();

    // Set up defeault company for GUI
    ui->radioForProfit->setChecked(true);
    ui->charitableLabel->setEnabled(false);
    ui->charitable->setEnabled(false);

    connect(ui->radioForProfit, SIGNAL(toggled(bool)), this, SLOT(radioChanged()));

    connect(ui->addCompany, SIGNAL(clicked()), this, SLOT(addCompany()));
}

MainWindow::~MainWindow()
{
    writeFile();
    delete ui;
}

void MainWindow::radioChanged()
{
    if (ui->radioForProfit->isChecked()) {
        ui->employeesLabel->setEnabled(true);
        ui->employees->setEnabled(true);
        ui->charitableLabel->setEnabled(false);
        ui->charitable->setEnabled(false);
    }
    else {
        ui->employeesLabel->setEnabled(false);
        ui->employees->setEnabled(false);
        ui->charitableLabel->setEnabled(true);
        ui->charitable->setEnabled(true);
    }
}

void MainWindow::addCompany()
{
    // get data from GUI and create an appropriate object type
    if (ui->name->text().size() > 0) // preventing blank names
    {
        QString name = ui->name->text();
        QDate date = ui->date->date();

        Company *c;
        if (ui->radioForProfit->isChecked()) {
            int employees = ui->employees->value();
            c = new CompanyForProfit(name, date, employees);
        }
        else {
            bool charitable = ui->charitable->isChecked();
            c = new CompanyNotForProfit(name, date, charitable);
        }
        ui->name->clear();
        ui->date->setDate(QDate::currentDate());
        ui->employees->setValue(0);
        ui->charitable->setChecked(false);

        list->addCompany(c);
        updateDisplay();
    }
}

void MainWindow::updateDisplay()
{
    // display company list in alphabeit order
    ui->displayList->clear();
    QStringList displayList = list->getlist();
    displayList.sort();
    foreach(QString company, displayList)
        ui->displayList->append(company);
}

void MainWindow::writeFile()
{
    if (list->size()>0) {
        FileWriter writer("backup.txt");
        writer.write(list->getlist());
    }
}
