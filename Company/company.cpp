#include "company.h"

Company::Company(QString n, QDate d):
    name(n), date(d){

}

Company::~Company()
{

}

QString Company::toString() const {
    QString output;
    output = name + ", " + date.toString("yyyy/MM/dd");
    return output;
}