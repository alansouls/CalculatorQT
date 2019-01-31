#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    calculatorState = 0;
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

double MainWindow::formNumberToDisplay(int num){
    double currentNum = ui->lcdNumber->value();
    if(calculatorState < 5){
        if(qFuzzyIsNull(currentNum)){
            return num;
        }else{
            return (currentNum*10 + num);
        }
    }else if (calculatorState < 10){
        if(qFuzzyIsNull(currentNum)){
            return num/10;
        }else{
            double auxNum = currentNum;
            for(int i =10;;i*=10){
                int intPartNum = auxNum/1;
                if(qFuzzyIsNull(auxNum - intPartNum)){
                    double dNum = num;
                    return currentNum + dNum/i;
                }
                auxNum*=10;
            }
        }
    }
    return 1;
}

MainWindow::~MainWindow()
{
    delete ui;
}

slots void MainWindow::buttonClicked(){
    QPushButton* buttonReciever = static_cast<QPushButton*>(sender());
    for(int i = 0;i <= 9;i++){
        if(buttonReciever->text()[0] == i + '0'){
            myLCD->display(formNumberToDisplay(i));
        }
    }
    if(buttonReciever->text()[0] == '.'){
        calculatorState += 5;
    }
}
