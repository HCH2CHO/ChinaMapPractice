#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QInputDialog>
#include <QToolTip>
#include <QLabel>
#include <QLineEdit>
#include <QPainter>
#include <QSplitter>
#include "caprfileload.h"
#include "myopenglwidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(CAprMap *map, QWidget *parent = 0);
    ~MainWindow();
/*
    void mouseMoveEvent(QMouseEvent *event);//鼠标移动事件
    void mousePressEvent(QMouseEvent *event);//鼠标按下事件
    void mouseReleaseEvent(QMouseEvent *event);//鼠标释放事件
    void mouseDoubleClickEvent(QMouseEvent *event);//鼠标双击事件
*/
private:
    Ui::MainWindow *ui;
    MyOpenGLWidget *openGLWidget;

    //QLabel *statusLabel;//显示鼠标移动时的实时位置
    //QLabel *mousePointLabel;//显示鼠标位置
};

#endif // MAINWINDOW_H
