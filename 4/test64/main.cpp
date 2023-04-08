#include <QtWidgets>
#include <iostream>
#include <string>
#include <QString>
#include "machine.h"
using namespace std;

int main(int args, char *argv[]) {
    cout << "Test N6.4: OK." << endl;

    Machine car;
    string x, p, v;
    QString QX, QP, QV;

    x="X: " + to_string(car.X);
    p="P: " + to_string(car.P);
    v="V: " + to_string(car.V);

    QX = QString::fromStdString(x);
    QP = QString::fromStdString(p);
    QV = QString::fromStdString(v);

    QApplication app(args, argv);
    QMainWindow mainWin;

    QLabel *xCarLabel = new QLabel(&mainWin);
    xCarLabel->setText(QX);
    QLabel *pCarLabel = new QLabel(&mainWin);
    pCarLabel->setText(QP);
    QLabel *vCarLabel = new QLabel(&mainWin);
    vCarLabel->setText(QV);

    xCarLabel->setGeometry(5,10,50,20);
    pCarLabel->setGeometry(5,30,50,20);
    vCarLabel->setGeometry(5,50,50,20);


    mainWin.show();
    return app.exec();
}





