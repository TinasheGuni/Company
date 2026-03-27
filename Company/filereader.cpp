#include "filereader.h"

#include <QFile>
#include <QTextStream>
#include <QStringList>
#include "companyforprofit.h"
#include "companynotforprofit.h"

FileReader::FileReader() {}

void FileReader::read(QString fileName, CompanyList *list)
{
    QFile file(fileName);
    QStringList data;
    if (file.exists()) {
        if (file.open(QIODevice::ReadOnly)) {
            QTextStream input(&file);
            while (!input.atEnd())
                data.append(input.readLine());
            file.close();
        }
    }

    foreach(QString str, data) {
        Company *c;
        QStringList holdData = str.split(",");
        QString n = holdData.at(0);
        QDate d = QDate::fromString(holdData.at(1), "yyyy/MM/dd");
        QString var = holdData.at(2);
        if (var == "true" || var == "false") {
            bool b = (var=="true"? true:false);
            c = new CompanyNotForProfit(n, d, b);
        }
        else {
            int i = var.toInt();
            c = new CompanyForProfit(n, d, i);
        }
        list->addCompany(c);
    }
}
