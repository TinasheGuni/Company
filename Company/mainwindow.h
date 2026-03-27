#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "companylist.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void radioChanged();
    void addCompany();

private:
    void updateDisplay();
    void writeFile();

    Ui::MainWindow *ui;
    CompanyList *list;
};
#endif // MAINWINDOW_H
