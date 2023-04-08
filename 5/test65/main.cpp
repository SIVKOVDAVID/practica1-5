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
