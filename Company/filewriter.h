#ifndef FILEWRITER_H
#define FILEWRITER_H

#include <QString>

class FileWriter
{
public:
    FileWriter(QString f);
    void write(QStringList list) const;

private:
    QString fileName;
};

#endif // FILEWRITER_H
