#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "QFile"
#include "QTextStream"
#include "entity.h"
 #include <QStringList>

class FileManager
{
public:
    FileManager();
    QFile outputfile;
    QString outputfilename;

    QFile inputfile;
    QString inputfilename;

    int OpenOutputFile();
    int CloseOutputFile();
    int WriteFile(QString );

    int OpenInputFile();
    int CloseInputFile();
    Entity ReadFile( );
    Entity ParseVHDL(QTextStream *ts);
    void CleanUpNameAndType(QString *Name,QString *Type);
    void CheckWireType(QString *busSize, char *busType,QString *Type);
};

#endif // FILEMANAGER_H
