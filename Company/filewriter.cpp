#include "filewriter.h"

#include <QFile>
#include <QTextStream>

FileWriter::FileWriter(QString f): fileName(f)
{}

void FileWriter::write(QStringList list) const
{
    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream output(&file);

        foreach(QString str, list)
            output << str << "\n";

        file.close();
    }
}
