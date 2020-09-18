#ifndef MYOPENGLWIDGET_H
#define MYOPENGLWIDGET_H

#include <QApplication>
#include <QWidget>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QPainter>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QToolTip>
#include <QStatusBar>
#include <QLabel>
#include <QPixmap>
#include <QString>
#include <QMainWindow>
#include "caprmap.h"

using namespace std;

class QOpenGLShaderProgram;
class MyOpenGLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    MyOpenGLWidget(CAprMap* map,QWidget* parent = nullptr);
    CAprMap *map;




protected:

    void paintEvent(QPaintEvent *event);


    void mouseMoveEvent(QMouseEvent *event);//鼠标移动事件
    void mousePressEvent(QMouseEvent *event);//鼠标按下事件
    void mouseReleaseEvent(QMouseEvent *event);//鼠标释放事件
    void mouseDoubleClickEvent(QMouseEvent *event);//鼠标双击事件




private:
    QOpenGLShaderProgram *program;

    bool isUpdated;//重绘信号

    QPixmap tempPix;//临时缓冲区
    QColor capitalColor;//省会颜色
    int radius;//省会半径
    int click_x;//点击点坐标
    int click_y;

    QLabel *mousePointLabel;//显示鼠标位置

    bool isMapLoaded;

    QPoint wcTOdc(long x,long y);//从窗口坐标向地理坐标转换
    QPoint dcTOwc(long x,long y);//从地理坐标向窗口坐标转换

signals:

public slots:
};

#endif // MYOPENGLWIDGET_H
