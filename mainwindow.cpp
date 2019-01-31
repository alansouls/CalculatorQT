#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    myLCD = ui->lcdNumber;
    myButtons[0] = ui->pushButton;
    myButtons[1] = ui->pushButton_2;
    myButtons[2] = ui->pushButton_3;
    myButtons[3] = ui->pushButton_4;
    myButtons[4] = ui->pushButton_5;
    myButtons[5] = ui->pushButton_6;
    myButtons[6] = ui->pushButton_7;
    myButtons[7] = ui->pushButton_8;
    myButtons[8] = ui->pushButton_9;
    myButtons[9] = ui->pushButton_10;
    myButtons[10] = ui->pushButton_11;
    myButtons[11] = ui->pushButton_12;
    myButtons[12] = ui->pushButton_13;
    myButtons[13] = ui->pushButton_14;
    myButtons[14] = ui->pushButton_15;
    myButtons[15] = ui->pushButton_16;
    for(int i = 0;i < 16;i++){
        QObject::connect(myButtons[i],SIGNAL(clicked()),this,SLOT(buttonClicked()));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

slots void MainWindow::buttonClicked(){
    myLCD->display(1.2);
}
