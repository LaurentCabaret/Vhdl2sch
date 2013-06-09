#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "QFile"
#include "QTextStream"
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
    QString ReadFile( );
};

#endif // FILEMANAGER_H
