#include "filemanager.h"
#include "QDebug"

FileManager::FileManager()
{
    outputfilename = QString("./test.tex");
    outputfile.setFileName(outputfilename);
    inputfilename = QString("./test.vhd");
    inputfile.setFileName(inputfilename);
    OpenInputFile();
    CloseInputFile();
    OpenOutputFile();
    CloseOutputFile();
}


int FileManager::OpenOutputFile()
{
    CloseOutputFile();
    if (!outputfile.open(QFile::ReadWrite | QFile::Truncate))
            return 0;
    else return 1;
}


int FileManager::CloseOutputFile()
{
    outputfile.close();
}


int FileManager::WriteFile(QString texte)
{
    qDebug()<< "WriteFile";
    if (OpenOutputFile()) {

    QTextStream out(&outputfile);
    out << texte;
    CloseOutputFile();
    return 1;
    }
    else return 0;

}


int FileManager::OpenInputFile() {
    CloseInputFile();
    if (!inputfile.open(QFile::ReadOnly))
            return 0;
    else return 1;
}

int FileManager::CloseInputFile(){
    inputfile.close();
}

QString FileManager::ReadFile() {
    qDebug()<< "ReadFile";
    if (OpenInputFile()) {

    QTextStream in(&inputfile);
    //out << texte;
    CloseInputFile();
    return "1";
    }
    else return "0";
}
