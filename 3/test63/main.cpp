#include <QtWidgets>
#include <iostream>
#include <string>
#include <QString>
#include "road.h"
using namespace std;

int main(int args, char *argv[]) {
    cout << "Test N6.3: OK." << endl;

    Road road;
    string alfa,beta;
    QString QAlfa, QBeta;

    alfa="A: " + to_string(road.Length);
    beta="B: " + to_string(road.Width);

    QAlfa = QString::fromStdString(alfa);
    QBeta = QString::fromStdString(beta);

    QApplication app(args, argv);
    QMainWindow mainWin;

    QLabel *lengthLabel = new QLabel(&mainWin);
    lengthLabel->setText(QAlfa);
    QLabel *widthLabel = new QLabel(&mainWin);
    widthLabel->setText(QBeta);

    lengthLabel->setGeometry(5,10,50,20);
    widthLabel->setGeometry(5,30,50,20);

    mainWin.show();
    return app.exec();
}






