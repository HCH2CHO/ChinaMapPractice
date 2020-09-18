#include "myopenglwidget.h"
#include <QOpenGLShaderProgram>

MyOpenGLWidget::MyOpenGLWidget(CAprMap *map, QWidget *parent)
    :QOpenGLWidget(parent)
{
    this->map = map;
    //resize(800,600);
    setGeometry(0,35,800,600);

    //显示鼠标位置
    mousePointLabel = new QLabel(tr(""),this);
    mousePointLabel->setFont(QFont("Arial",10,QFont::Bold,true));
    mousePointLabel->setFixedWidth(250);

    //鼠标跟踪
    setMouseTracking(true);

    isUpdated = 0;
    capitalColor = QColor(255, 255, 255);
    radius = 1;

}



void MyOpenGLWidget::paintEvent(QPaintEvent *event)
{
    if(map->layers.empty())
        return;

    QPainter painter(this);
    painter.setBackground(Qt::white);
    painter.fillRect(event->rect(),Qt::white);
    tempPix = QPixmap(this->width(),this->height());
    tempPix.fill(Qt::white);
    painter.begin(&tempPix);

    //反走样
    painter.setRenderHint(QPainter::Antialiasing,true);
    //抗锯齿
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);

    //设置绘制窗口大小
    int width = map->rect.right()-map->rect.left();
    int height = map->rect.bottom()-map->rect.top();
    painter.setWindow(map->rect.left(),map->rect.top(),width,height);

    //绘制图层
    for(vector<CAprLayer>::iterator it = map->layers.begin();it != map->layers.end();it++)
        (*it).Draw(painter);


    //绘制省会
    for(vector<CAprCity>::iterator it = map->cities.begin();it != map->cities.end();it++)
    {
        QPoint point = (*it).point;
        //如果在点击范围内，省会颜色变色
        painter.setBrush(QBrush(QColor(255, 0, 0), Qt::SolidPattern));
        painter.drawEllipse(point, 10000,10000);

        if((click_x-point.x()<10000)&&(click_x-point.x()>-10000)&&(click_y-point.y()<10000)&&(click_y-point.y()>-10000))
        {
            painter.setBrush(QBrush(capitalColor, Qt::SolidPattern));
            painter.drawEllipse(point,10000, 10000);
        }

    }

    painter.end();
    isMapLoaded = true;
}


/*
QPoint MyOpenGLWidget::dcTOwc(long x,long y)
{
    int dc_x = map->rect.width()/tempPix.width();
    int dc_y = map->rect.height()/tempPix.height();
    x = (x - map->rect.left())/dc_x;
    y = (y - map->rect.top())/dc_y;

    x=x/scale+offset.x();
    y=y/scale+offset.y();
}*/

//实现从屏幕坐标到地理坐标的转换
QPoint MyOpenGLWidget::wcTOdc(long x, long y)
{
    int scale_x = (map->rect.width())/this->width();
    int scale_y = (map->rect.height())/this->height();

    x = map->rect.left()+x*scale_x;
    y = map->rect.top()+y*scale_y;
    QPoint point(x,y);
    return point;
}



void MyOpenGLWidget::mouseMoveEvent(QMouseEvent *event)
{
    if(!isMapLoaded)
        return;

    //获取点击位置坐标
    int x = event->pos().x();
    int y = event->pos().y();

    //坐标转换
    QPoint point = wcTOdc(x,y);

    //显示坐标信息
    mousePointLabel->setText("position:"+QString::number(point.x())+", "+QString :: number(point.y()));

}

void MyOpenGLWidget::mousePressEvent(QMouseEvent *event)
{
    //如果是鼠标左键按下
    if(event->button() == Qt::LeftButton)
    {
        QCursor cursor;
        cursor.setShape(Qt::ClosedHandCursor);
        //使鼠标暂时改变形状
        QApplication::setOverrideCursor(cursor);
        //获取助阵位置和窗口位置的差值
        //offset = event->globalPos() - pos();
    }

}

void MyOpenGLWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if(!isMapLoaded)
        return;

    //恢复鼠标形状
    QApplication::restoreOverrideCursor();

    int x = event->pos().x();
    int y = event->pos().y();
    QPoint point = this->wcTOdc(x,y);//窗口坐标到地理坐标转换
    //获取点击点坐标
    click_x = point.x();
    click_y = point.y();
    //将点击到的省会颜色变蓝
    capitalColor = QColor(0,0,255);
    //点击到的省会半径为4
    radius = 4;
    //QString str = "("+QString :: number(point.x()) +", "+QString::number(point.y())+")";
    //mousePointLabel->setText("position:" + str);
    //更新paintevent
    update();
    repaint();
}

void MyOpenGLWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(!isMapLoaded)
        return;

    //如果是鼠标左键按下
    if(event->button()==Qt::LeftButton)
    {
        //如果现在不是全屏，将窗口设置为全屏
        if(windowState()!=Qt::WindowFullScreen)
            setWindowState(Qt::WindowFullScreen);
        //否则恢复以前的大小
        else setWindowState(Qt::WindowNoState);
    }
}




























