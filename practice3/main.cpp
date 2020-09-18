#include "mainwindow.h"
#include <QApplication>
#include <string>
#include <QDir>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    CAprFileload file;
    file.LoaddataFile("./data/china.dat");
    file.LoadoptFile("./data/china.opt");
    file.LoadtxtFile("./data/chnCity.txt");
    /*相对路径指向编译文件的Makefile
    QString p=QDir::currentPath();
    string s = p.toStdString();
    printf("%s",s.c_str());
    */
    MainWindow w(file.map);
    w.show();
    return a.exec();
}
