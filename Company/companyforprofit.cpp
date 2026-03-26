#include "companyforprofit.h"

CompanyForProfit::CompanyForProfit(QString n, QDate d, int e):
    Company(n, d), employees(e)
{}

QString CompanyForProfit::toString() const
{
    QString output;
    output = Company::toString() + "," + QString::number(employees);
    return output;
}
