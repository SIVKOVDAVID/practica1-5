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


