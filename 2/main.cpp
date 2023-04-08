#include <QtWidgets>
#include <iostream>
#include <string>
#include <QString>
using namespace std;

int main(int args, char *argv[]) {
    cout << "Test v6.2: OK." << endl;

    int a=1000,b=777;
    string alfa,beta;
    QString QAlfa, QBeta;

    alfa="A: " + to_string(a);
    beta="B: " + to_string(b);

    QAlfa = QString::fromStdString(alfa);
    QBeta = QString::fromStdString(beta);

    QApplication app(args, argv);
    QMainWindow mainWin;

    QLabel *textLabel1 = new QLabel(&mainWin);
    textLabel1->setText(QAlfa);
    QLabel *textLabel2 = new QLabel(&mainWin);
    textLabel2->setText(QBeta);

    textLabel1->setGeometry(5,10,50,20);
    textLabel2->setGeometry(5,30,50,20);

    mainWin.show();
    return app.exec();
}


