#include "actions.h"
#include <QGridLayout>

Actions::Actions(QWidget *parent)
    : QWidget(parent) {
    QPushButton *oneBtn = new QPushButton("1", this);
    QPushButton *twoBtn = new QPushButton("2", this);
    QPushButton *thrBtn = new QPushButton("3", this);
    QPushButton *forBtn = new QPushButton("4", this);
    QPushButton *fivBtn = new QPushButton("5", this);
    QPushButton *sixBtn = new QPushButton("6", this);
    QPushButton *sevBtn = new QPushButton("7", this);
    QPushButton *eigBtn = new QPushButton("8", this);
    QPushButton *ninBtn = new QPushButton("9", this);
    QPushButton *zerBtn = new QPushButton("0", this);
    QPushButton *poiBtn = new QPushButton(".", this);
    QPushButton *equBtn = new QPushButton("=", this);
    QPushButton *plsBtn = new QPushButton("+", this);
    QPushButton *mnsBtn = new QPushButton("-", this);
    QPushButton *mltBtn = new QPushButton("*", this);
    QPushButton *dvdBtn = new QPushButton("/", this);
    QPushButton *clrBtn = new QPushButton("C", this);
    lbl = new QLabel("", this);

    QGridLayout *grid = new QGridLayout(this);
    grid->addWidget(lbl, 0, 1);
    grid->addWidget(clrBtn, 0, 3);
    grid->addWidget(plsBtn, 1, 3);
    grid->addWidget(mnsBtn, 2, 3);
    grid->addWidget(mltBtn, 3, 3);
    grid->addWidget(dvdBtn, 4, 3);
    grid->addWidget(oneBtn, 1, 0);
    grid->addWidget(twoBtn, 1, 1);
    grid->addWidget(thrBtn, 1, 2);
    grid->addWidget(forBtn, 2, 0);
    grid->addWidget(fivBtn, 2, 1);
    grid->addWidget(sixBtn, 2, 2);
    grid->addWidget(sevBtn, 3, 0);
    grid->addWidget(eigBtn, 3, 1);
    grid->addWidget(ninBtn, 3, 2);
    grid->addWidget(zerBtn, 4, 1);
    grid->addWidget(poiBtn, 4, 0);
    grid->addWidget(equBtn, 4, 2);

    setLayout(grid);

    connect(plsBtn, &QPushButton::clicked, this, &Actions::Addition);
    connect(mnsBtn, &QPushButton::clicked, this, &Actions::Subtraction);
    connect(mltBtn, &QPushButton::clicked, this, &Actions::Multiplication);
    connect(dvdBtn, &QPushButton::clicked, this, &Actions::Division);
    connect(oneBtn, &QPushButton::clicked, this, &Actions::InputOne);
    connect(twoBtn, &QPushButton::clicked, this, &Actions::InputTwo);
    connect(thrBtn, &QPushButton::clicked, this, &Actions::InputThree);
    connect(forBtn, &QPushButton::clicked, this, &Actions::InputFour);
    connect(fivBtn, &QPushButton::clicked, this, &Actions::InputFive);
    connect(sixBtn, &QPushButton::clicked, this, &Actions::InputSix);
    connect(sevBtn, &QPushButton::clicked, this, &Actions::InputSeven);
    connect(eigBtn, &QPushButton::clicked, this, &Actions::InputEight);
    connect(ninBtn, &QPushButton::clicked, this, &Actions::InputNine);
    connect(zerBtn, &QPushButton::clicked, this, &Actions::InputZero);
    connect(poiBtn, &QPushButton::clicked, this, &Actions::InputPoint);
    connect(equBtn, &QPushButton::clicked, this, &Actions::Equals);
    connect(clrBtn, &QPushButton::clicked, this, &Actions::Clear);
}

void Actions::InputOne() {
    Actions::numbers.append("1");
    lbl->setText(Actions::numbers);
}

void Actions::InputTwo() {
    Actions::numbers.append("2");
    lbl->setText(Actions::numbers);
}

void Actions::InputThree() {
    Actions::numbers.append("3");
    lbl->setText(Actions::numbers);
}

void Actions::InputFour() {
    Actions::numbers.append("4");
    lbl->setText(Actions::numbers);
}

void Actions::InputFive() {
    Actions::numbers.append("5");
    lbl->setText(Actions::numbers);
}

void Actions::InputSix() {
    Actions::numbers.append("6");
    lbl->setText(Actions::numbers);
}

void Actions::InputSeven() {
    Actions::numbers.append("7");
    lbl->setText(Actions::numbers);
}

void Actions::InputEight() {
    Actions::numbers.append("8");
    lbl->setText(Actions::numbers);
}

void Actions::InputNine() {
    Actions::numbers.append("9");
    lbl->setText(Actions::numbers);
}

void Actions::InputZero() {
    Actions::numbers.append("0");
    lbl->setText(Actions::numbers);
}

void Actions::InputPoint() {
    Actions::numbers.append(".");
    lbl->setText(Actions::numbers);
}

void Actions::Addition() {
    Actions::first = lbl->text().toFloat();
    lbl->setText("+");
    Actions::id = 1;
    Actions::numbers = "";
}

void Actions::Subtraction() {
    Actions::first = lbl->text().toFloat();
    lbl->setText("-");
    Actions::id = 2;
    Actions::numbers = "";
}

void Actions::Multiplication() {
    Actions::first = lbl->text().toFloat();
    lbl->setText("*");
    Actions::id = 3;
    Actions::numbers = "";
}

void Actions::Division() {
    Actions::first = lbl->text().toFloat();
    lbl->setText("/");
    Actions::id = 4;
    Actions::numbers = "";
}

void Actions::Equals() {
    float result = 0;
    Actions::second = lbl->text().toFloat();
    lbl->setText("");
    switch (id) {
    case 1:
        result = Actions::first + Actions::second;
        lbl->setText(QString::number(result));
        break;
    case 2:
        result = Actions::first - Actions::second;
        lbl->setText(QString::number(result));
        break;
    case 3:
        result = Actions::first * Actions::second;
        lbl->setText(QString::number(result));
        break;
    case 4:
        if (Actions::second != 0) {
            result = Actions::first / Actions::second;
        } else {
            lbl->setText("Divided by 0!");
            break;
        }
        lbl->setText(QString::number(result));
        break;
    }
    Actions::numbers = "";
}

void Actions::Clear() {
    lbl->setText("");
    Actions::numbers = "";
}
