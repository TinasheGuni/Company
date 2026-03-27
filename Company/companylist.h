#ifndef COMPANYLIST_H
#define COMPANYLIST_H

#include <QList>
#include <QStringList>
#include "company.h"

class CompanyList
{
public:
    CompanyList();
    ~CompanyList();
    void addCompany(Company *c);
    QStringList getlist() const;
    int size() const;

private:
    QList<Company *> list;
};

#endif // COMPANYLIST_H
