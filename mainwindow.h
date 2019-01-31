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
    bool isDisplayReseted;
    //Methods
    void setDisplay();
    void resetDisplay();
    void sum();
    void sub();
    void mul();
    void div();


private  slots:
    void buttonClicked();
};


#endif // MAINWINDOW_H
