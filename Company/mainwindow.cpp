#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "company.h"
#include "companyforprofit.h"
#include "companynotforprofit.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
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
    }
}

void MainWindow::updateDisplay()
{
    ui->displayList->clear();
}
