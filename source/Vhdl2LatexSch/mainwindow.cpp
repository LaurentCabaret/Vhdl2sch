#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "filemanager.h"
#include "entity.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    FileManager Fmng;
    Fmng.OpenOutputFile();
    Entity lEntite;
    Fmng.WriteFile(lEntite.GetLatexFull());
    Fmng.CloseOutputFile();
    system("lualatex  -interaction=nonstopmode test.tex");
    system("evince test.pdf");
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}
