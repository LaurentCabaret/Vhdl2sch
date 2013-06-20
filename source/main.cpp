#include <QApplication>
#include "mainwindow.h"

#include <QTextCodec>
#include <QString>
#include <QDebug>
#include "filemanager.h"
#include "entity.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
  int count;

    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

    FileManager Fmng;
    QStringList l;
    qDebug() << argv[1];
    if (argc > 1)
       {
         Fmng.inputfilename = argv[1];

       }
     else
       {
             Fmng.inputfilename = "test.vhd";
       }
    Fmng.inputfile.setFileName(Fmng.inputfilename);


    Entity lEntite;
    lEntite = Fmng.ReadFile();
    lEntite.AdjustSize();
    Fmng.WriteFile(lEntite.GetLatexFull());
    Fmng.CloseOutputFile();
    QString Command;
    l = Fmng.inputfilename.split(".");
    Command = "cp schematic.pdf " + l[0] + ".pdf";

    system("lualatex  -interaction=nonstopmode schematic.tex");
    system("evince schematic.pdf");
    system(qPrintable(Command));
    return a.exec();
}
