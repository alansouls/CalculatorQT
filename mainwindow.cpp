#include "mainwindow.h"
#include "ui_mainwindow.h"
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

bool  MainWindow::button1IsClicked(){
    if(ui->)
}
MainWindow::~MainWindow()
{
    delete ui;
}
