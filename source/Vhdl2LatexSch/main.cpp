#include <QApplication>
#include "mainwindow.h"

#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

    w.setWindowTitle("VHDL to Latex Schematic (Tikz/pgf)");
    w.show();

    return a.exec();
}
