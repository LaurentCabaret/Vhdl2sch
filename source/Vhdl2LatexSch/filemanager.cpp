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
    unsigned int busSize;
    QString EntName;
    QString Name;
    QString Type;
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
            if (line.contains(": in", Qt::CaseInsensitive)) {
                l = line.split(": in");
                Name = l[0];
                Name.remove("port");
                Name.remove("Port");
                Name.remove("PORT");
                Name.remove("(");
                Name.remove(")");
                Name.remove(" ");
                Name.remove("_");

                Type = l[1];
                Type.remove(" ");
                Type.remove("(");
                Type.remove(")");
                Type.remove(";");
                Type = Type.toUpper();
                if (Type == "STD_LOGIC")
                    Ent.CreateInput(Name,WIRE,1);
                else {
                    if (Type.contains("STD_LOGIC_VECTOR")) {
                        Type.remove("STD_LOGIC_VECTOR");
                        if (Type.contains("DOWNTO", Qt::CaseInsensitive)) {
                            l = Type.split("DOWNTO");
                            busSize = l[0].toInt() + l[1].toInt() + 1;
                        }
                        Ent.CreateInput(Name,BUS,busSize);
                    }
                }
            }

            if (line.contains(": out", Qt::CaseInsensitive)) {
                l = line.split(": out");
                Name = l[0];
                Name.remove("port");
                Name.remove("(");
                Name.remove(")");
                Name.remove(" ");
                Name.remove("\t");
                Name.remove("_");

                Type = l[1];
                Type.remove(" ");
                Type.remove("(");
                Type.remove(")");
                Type.remove(";");
                Type = Type.toUpper();
                if (Type == "STD_LOGIC")
                    Ent.CreateOutput(Name,WIRE,1);
                else {
                    if (Type.contains("STD_LOGIC_VECTOR")) {
                        Type.remove("STD_LOGIC_VECTOR");
                        if (Type.contains("DOWNTO", Qt::CaseInsensitive)) {
                            l = Type.split("DOWNTO");
                            busSize = l[0].toInt() + l[1].toInt() + 1;
                        }
                        Ent.CreateOutput(Name,BUS,busSize);
                    }
                }
            }

        }
    }
    return Ent;

}

