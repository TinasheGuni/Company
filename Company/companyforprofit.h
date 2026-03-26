#ifndef COMPANYFORPROFIT_H
#define COMPANYFORPROFIT_H

#include "company.h"

class CompanyForProfit : public Company
{
public:
    CompanyForProfit(QString n, QDate d, int e);
    QString toString() const;

private:
    int employees;
};

#endif // COMPANYFORPROFIT_H
