#ifndef COMPANYNOTFORPROFIT_H
#define COMPANYNOTFORPROFIT_H

#include "company.h"

class CompanyNotForProfit : public Company
{
public:
    CompanyNotForProfit(QString n, QDate d, bool c);
    QString toString() const;

private:
    bool charitable;
};

#endif // COMPANYNOTFORPROFIT_H
