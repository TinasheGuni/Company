#include "companylist.h"

CompanyList::CompanyList() {}

CompanyList::~CompanyList()
{
    qDeleteAll(list);
    list.clear();
}

void CompanyList::addCompany(Company *c)
{
    list.append(c);
}

QStringList CompanyList::getlist() const
{
    QStringList templist;
    for (int i = 0; i < list.size(); i++) {
        templist.append(list.at(i)->toString());
    }
    return templist;
}

int CompanyList::size() const
{
    return list.size();
}
