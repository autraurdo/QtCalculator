#ifndef ACTIONS_H
#define ACTIONS_H

#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QLabel>

class Actions : public QWidget
{
    Q_OBJECT
public:
    Actions(QWidget *parent = 0);
private slots:
    void InputOne();
    void InputTwo();
    void InputThree();
    void InputFour();
    void InputFive();
    void InputSix();
    void InputSeven();
    void InputEight();
    void InputNine();
    void InputZero();
    void InputPoint();
    void Addition();
    void Subtraction();
    void Multiplication();
    void Division();
    void Equals();
    void Clear();
private:
    QLabel *lbl;
    short id = 0;
    float first = 0;
    float second = 0;
    QString numbers = "";
};

#endif // ACTIONS_H
