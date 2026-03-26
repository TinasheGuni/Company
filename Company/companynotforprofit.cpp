#include "companynotforprofit.h"

CompanyNotForProfit::CompanyNotForProfit(QString n, QDate d, bool c):
    Company(n, d), charitable(c)
{}

QString CompanyNotForProfit::toString() const
{
    QString output;
    output = Company::toString() + "," + (charitable? "true": "false");
    return output;
}
