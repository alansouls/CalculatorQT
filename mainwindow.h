#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLCDNumber>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    //Variables
    Ui::MainWindow *ui;
    QPushButton *myButtons[16];
    QLCDNumber *myLCD;
    int calculatorState;
    double bufferValue;
    bool isBufferValueDisplayed;
    //Methods
    void resetDisplay();
    void sum(double x, double y);
    void sub(double x, double y);
    void mul(double x, double y);
    void div(double x, double y);
    double formNumberToDisplay(int num);
    void opMap(int state,double value);
    void processOperator();

private slots:
    void buttonClicked();
};

#endif // MAINWINDOW_H
