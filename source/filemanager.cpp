#include "filemanager.h"
#include "QDebug"
#include <QRegExpValidator>

FileManager::FileManager()
{
    inputfilename = QString("./test.vhd");
    inputfile.setFileName(inputfilename);
    outputfilename = QString("./schematic.tex");
    outputfile.setFileName(outputfilename);
    OpenInputFile();
    CloseInputFile();
    OpenOutputFile();
    CloseOutputFile();
}


int FileManager::OpenOutputFile()
{
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


int FileManager::OpenInputFile()
{
    if (!inputfile.open(QFile::ReadOnly))
        return 0;
    else return 1;
}

int FileManager::CloseInputFile(){
    inputfile.close();
}

Entity FileManager::ReadFile() {
    Entity Ent;
    qDebug()<< "ReadFile";
    OpenInputFile();
    QTextStream in(&inputfile);
    Ent = ParseVHDL(&in);
    CloseInputFile();
    return Ent;
}



Entity FileManager::ParseVHDL(QTextStream *ts) {
    QString line;
    Entity Ent;
    QString busSize;
    QString EntName;
    QString Name;
    QString Type;
    char busType;
    QStringList l;
    bool flag = true;
    while (flag == true) {
        line = ts->readLine();
        if (line.contains("entity", Qt::CaseInsensitive)) {
            EntName = line.remove("entity ", Qt::CaseInsensitive);
            EntName = line.remove(" is", Qt::CaseInsensitive);
            Ent.name = EntName;
            flag = false;
        }
    }

    flag = false;
    while (flag == false) {
        line = ts->readLine();
        flag = line.contains("end " + EntName, Qt::CaseInsensitive);
        l = line.split("--");
        line = l[0];

        if (flag==false) {
            if (line.contains("generic", Qt::CaseInsensitive)) {
                while (1) {
                    line = ts->readLine();
                    if (line.contains(")", Qt::CaseInsensitive)) {line = ts->readLine();break;}
                }
            }
            if (line.contains(": in", Qt::CaseInsensitive)) {
                l = line.split(": in");
                Name = l[0];
                Type = l[1];
                CleanUpNameAndType(&Name,&Type);
                CheckWireType(&busSize,&busType,&Type);
                Ent.CreateInput(Name,busType,busSize);
            }
        }

        if (line.contains(": out", Qt::CaseInsensitive)) {
            l = line.split(": out");
            Name = l[0];
            Type = l[1];
            CleanUpNameAndType(&Name,&Type);
            CheckWireType(&busSize,&busType,&Type);
            Ent.CreateOutput(Name,busType,busSize);
        }


        if (line.contains(": buffer", Qt::CaseInsensitive)) {
            l = line.split(": buffer");
            Name = l[0];
            Type = l[1];
            CleanUpNameAndType(&Name,&Type);
            Name = l[0];
            Type = l[1];
            CleanUpNameAndType(&Name,&Type);
            CheckWireType(&busSize,&busType,&Type);
            Ent.CreateOutput(Name,busType,busSize);

        }
    }

    return Ent;

}

void FileManager::CleanUpNameAndType(QString *Name,QString *Type) {
    Name->remove("port");
    Name->remove("Port");
    Name->remove("PORT");
    Name->remove("(");
    Name->remove(")");
    Name->remove(" ");
    Name->remove("\t");
    Name->remove("_");

    Type->remove(" ");
    Type->remove("(");
    Type->remove(")");
    Type->remove(";");
    *Type = Type->toUpper();
}


void FileManager::CheckWireType(QString *busSize, char *busType,QString *Type) {

    QRegExp rx( "[A-Z]" );
    QRegExpValidator validator(rx,0);
    int pos = 0;
    QStringList l,l2;
    QString UpperBusNumber;
    if (*Type == "STD_LOGIC") {
        *busType = WIRE;
        *busSize = 1;
    }
    else {
        if (Type->contains("STD_LOGIC_VECTOR")) {
            Type->remove("STD_LOGIC_VECTOR");
            if (Type->contains("DOWNTO", Qt::CaseInsensitive)) {
                l = Type->split("DOWNTO");
                UpperBusNumber = l[0];
                if (UpperBusNumber.contains("-")) {
                    l2 = UpperBusNumber.split("-");
                    UpperBusNumber = l2[0];
                    if (UpperBusNumber.count(rx)) {
                        *busSize = UpperBusNumber.toLower();
                        (*busSize)[0] = (*busSize)[0].toUpper();
                    }
                    else {
                        *busSize = QString::number(l2[0].toInt() - l2[1].toInt() - l[1].toInt() + 1);
                    }
                }
                else
                    *busSize = QString::number(l[0].toInt() - l[1].toInt() + 1);
            }
            else if (Type->contains("TO", Qt::CaseInsensitive)) {
                l = Type->split("TO");
                *busSize = QString::number(l[1].toInt() - l[0].toInt() + 1);
            }
            *busType = BUS;
        }
    }
}
