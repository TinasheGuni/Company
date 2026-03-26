#ifndef COMPANY_H
#define COMPANY_H

#include <QString>
#include <QDate>

class Company
{
public:
    Company(QString n, QDate d);
    virtual ~Company();
    virtual QString toString() const = 0;

private:
    QString name;
    QDate date;
};

#endif // COMPANY_H
