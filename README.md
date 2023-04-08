1. По примеру 8 из лекции создайте простейшее приложение с графическим интерфейсом с применением библиотеки Qt.

Исходный код:
//main.cpp
#include<iostream>
#include "road.h"
int main() {
	using namespace std;
	cout<<"Test v6.03: OK.\n";
	Road road;
	cout<<"Before Road width: "<<road.Width<<endl;
	road.Width=3;
	cout<<"Road width= "<<road.Width<<endl;
	return 0;
}
//road.h
class Road {
	public:
	Road();
	 double Length;
	 int    Width;
	 
};
Road::Road(){
	Length = 330;
	Width = 1;
}
Скриншоты:


Исходный код:
//road.h
#ifndef ROAD_H
#define ROAD_H
class Road {
	public:
	Road();
	 double Length;
	 int    Width;
	 
};

#endif
//main.cpp
#include<iostream>
#include "road.h"
int main() {
	using namespace std;
	cout<<"Test v6.03: OK.\n";
	Road road;
	cout<<"Before Road width: "<<road.Width<<endl;
	road.Width=3;
	cout<<"Road width= "<<road.Width<<endl;
	return 0;
}
//road.cpp
#include "road.h"

Road::Road(){
	Length = 330;
	Width = 1;
}
Скриншоты:


//main.cpp
#include<QtWidgets>
#include<iostream>
#include "road.h"
int main(int args, char *argv[]) {
	using namespace std;
	cout<<"Test v6.03: OK.\n";
	Road road;
	cout<<"Before Road width: "<<road.Width<<endl;
	road.Width=3;
	cout<<"Road width= "<<road.Width<<endl;
	
	QApplication app(argc, argv);
	QMainWindow mainWin;
	mainWin.show();
	return app.exec();
}
//road.h
#ifndef ROAD_H
#define ROAD_H
class Road {
	public:
	Road();
	 double Length;
	 int    Width;
	 
};

//road.cpp
#include "road.h"

Road::Road(){
	Length = 330;
	Width = 1;
}
//test63.pro
QT+=widgets
SOURCES+=main.cpp road.h road.cpp
Скриншот:

#include<QtWidgets>
#include<iostream>
#include "road.h"
class MainWindow : public QMainWindow {
	public:
	 MainWindow(Road *_road);
	private:
	 QLabel *widthLabel;
};
MainWindow::MainWindow(Road *_road){
	resize(1100,330);
	setWindowTitle("Road in Window");
	widthLabel = new QLabel(this);
	widthLabel->setGeometry(0, 0, 1000, 300);
	widthLabel->setFont(QFont("Courier",36,QFont::Bold));
	widthLabel->setText("Width"+QString::number(_road->Width));
}

int main(int argc, char *argv[]) {
	
	using namespace std;
	cout<<"Test v6.03: OK.\n";
	Road road;
	cout<<"Before Road width: "<<road.Width<<endl;
	road.Width=3;
	cout<<"Road width= "<<road.Width<<endl;
	
	
	QApplication app(argc, argv);
	MainWindow mainWin(&road);
	mainWin.show();
	return app.exec();
}

Скриншот:

Вывод: По примеру 8 из лекции создайте простейшее приложение с графическим интерфейсом с применением библиотеки Qt.


2. По примеру 8 из лекции создайте простейшее приложение с графическим интерфейсом с применением библиотеки Qt. В программе 2 переменным присваиваются числовые значения и выводятся в соответствующие компоненты textLabel1 и textLabel2 класса QLabel.
Скриншот

 //main.cpp
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
//test62
CONFIG += console
QT+=widgets
SOURCES += \
    ../main.cpp

Вывод: По примеру 8 из лекции создал простейшее приложение с графическим интерфейсом с применением библиотеки Qt. В программе 2-е переменные целочисленного типа, которые выводятся в соответствующие компоненты textLabel1 и textLabel2 класса QLabel.

3. Создайте приложение на основе проекта из задания 2, подключите библиотеку с классом Дорога. Выведите значения свойств класса, каждое - в отдельный компонент QLabel: lengthLabel, widthLabel.
Скриншот:

Исходный код:
//main.cpp
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
//road.cpp
#include "road.h"
Road::Road() : Length(1000), Width(777) {}


//road.h
#ifndef ROAD_H
#define ROAD_H

class Road {
public:
    int Length;
    int Width;
    Road();
};

#endif


//test63.pro
CONFIG += console
QT+=widgets
SOURCES += \
    main.cpp \
    road.cpp

HEADERS += \
    road.h


Вывод: Для создания приложения на основе проекта из задания 2 необходимо подключить библиотеку с классом Дорога. Далее, для отображения значений свойств класса необходимо создать два компонента QLabel: lengthLabel и widthLabel. Вывод значений свойств осуществляется с помощью методов setText() для каждого из компонентов.

4. Создайте приложение на основе проекта из задания 2, подключите библиотеку с классом Машина. Выведите значения свойств класса, каждое - в отдельный компонент QLabel: xCarLabel, vCarLabel, pCarLabel.
Скриншот:

Исходный код:
//main.cpp
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


//machine.h
#ifndef MACHINE_H
#define MACHINE_H

class Machine {
public:
    int X;
    int P;
    int V;
    Machine();
};

#endif



//machine.cpp
#include "machine.h"
Machine::Machine() : X(777), P(77), V(7777) {}
Вывод: Для создания приложения на основе проекта из задания 2 необходимо подключить библиотеку с классом Машина. Затем создайте три компонента QLabel - xCarLabel, vCarLabel и pCarLabel, для отображения значений свойств класса. Используйте метод setText() для каждого компонента, чтобы вывести соответствующее значение свойства.
5. Создайте приложение на основе проекта из задания 2, подключите библиотеку с классом TBook. Выведите значения свойств класса, каждое - в отдельный компонент QLabel: authorLabel, nameLabel, countLabel.
Скриншот:

Исходный код:
//tbook.cpp
#include "tbook.h"
TBook::TBook() : Author("Joanne Rowling"), Name("Harry Potter"), Count(70) {}
//tbook.h

#ifndef TBOOK_H
#define TBOOK_H

#include <string>
using namespace std;
class TBook {
public:
    string Author;
    string Name;
    int Count;
    TBook();
};

#endif


//main.cpp
#include <QtWidgets>
#include <iostream>
#include <string>
#include <QString>
#include "tbook.h"
using namespace std;

int main(int args, char *argv[]) {
    cout << "Test N6.5: OK." << endl;

    TBook book;
    string bookauthor, bookname, bookcount;
    QString QBA, QBN, QBC;

    bookauthor = "Author: " + book.Author;
    bookname = "Name: " + book.Name;
    bookcount = "Count: " + to_string(book.Count);

    QBA = QString::fromStdString(bookauthor);
    QBN = QString::fromStdString(bookname);
    QBC = QString::fromStdString(bookcount);

    QApplication app(args, argv);
    QMainWindow mainWin;

    QLabel *authorLabel = new QLabel(&mainWin);
    authorLabel->setText(QBA);
    QLabel *nameLabel = new QLabel(&mainWin);
    nameLabel->setText(QBN);
    QLabel *countLabel = new QLabel(&mainWin);
    countLabel->setText(QBC);

    authorLabel->setGeometry(5,10,150,20);
    nameLabel->setGeometry(5,30,150,20);
    countLabel->setGeometry(5,50,150,20);

    mainWin.show();
    return app.exec();
}


Вывод: Для создания приложения нужно подключить библиотеку с классом Дорога, затем создать два компонента QLabel для отображения значений свойств класса - lengthLabel и widthLabel. Для вывода значений свойств используйте метод setText() для каждого из компонентов. При подключении библиотеки с классом Дорога необходимо убедиться, что путь к файлу с классом указан правильно. Для корректного отображения значений свойств класса в компонентах QLabel рекомендуется использовать форматирование строк или конкатенацию значений. Готовое приложение можно запустить и проверить его работу.



