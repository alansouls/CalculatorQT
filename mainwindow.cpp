#include "mainwindow.h"
#include "ui_mainwindow.h"
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    myLCD = ui->lcdNumber;
    calculatorState = 0;
    isBufferValueDisplayed = true;
    bufferValue = 0;
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
            double dNum = num;
            return dNum/10;
        }else{
            double auxNum = currentNum;
            for(int i =10;;i*=10){
                int intPartNum = static_cast<int>(auxNum);
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
    if(isBufferValueDisplayed == true){
        myLCD->display(0);
        isBufferValueDisplayed = false;
    }
    for(int i = 0;i <= 9;i++){
        if(buttonReciever->text()[0] == i + '0'){
            myLCD->display(formNumberToDisplay(i));
        }
    }
    if(buttonReciever->text()[0] == '.'){
        if(calculatorState < 5){
            calculatorState += 5;
        }
    }else if(buttonReciever->text()[0] == '+'){
        if(calculatorState == 0 || calculatorState == 5){
            bufferValue = myLCD->value();
            myLCD->display(0.0);
        }else{
            if(calculatorState < 5){
                opMap(calculatorState,myLCD->value());
            }else{
                opMap(calculatorState - 5,myLCD->value());
            }
            bufferValue = myLCD->value();
            isBufferValueDisplayed = true;
        }
        calculatorState = 1;
    }

}

void MainWindow::opMap(int state,double value){
    switch(state){
        case 1:
            sum(bufferValue,value);
        break;
        case 2:
            sub(bufferValue,value);
        break;
        case 3:
            sub(bufferValue,value);
        break;
        case (4):
            mul(bufferValue,value);
        break;
        default:
        break;
    }
}

void MainWindow::sum(double x, double y){
    myLCD->display(x+y);
}
void MainWindow::sub(double x, double y){
    myLCD->display(x-y);
}
void MainWindow::mul(double x, double y){
    myLCD->display(x*y);
}
void MainWindow::div(double x, double y){
    if(qFuzzyIsNull(y)){
        myLCD->display("ERRO");
    }
    myLCD->display(x/y);
}

