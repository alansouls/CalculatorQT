#include "mainwindow.h"
#include "ui_mainwindow.h"
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

<<<<<<< HEAD
MainWindow::button1IsClicked(){
=======
bool  MainWindow::button1IsClicked(){
>>>>>>> something
    if(ui->)
}
MainWindow::~MainWindow()
{
    delete ui;
}
