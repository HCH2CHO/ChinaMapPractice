#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(CAprMap *map, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //设置窗口标题
    setWindowTitle("Map of China              2015301130105 wangmengxue and 2015301130034 xuwubin");
    //设置窗口大小
    resize(1200,660);

    setMouseTracking(true);

    openGLWidget = new MyOpenGLWidget(map,this);
    //setCentralWidget(openGLWidget);

    //显示鼠标位置
    //mousePointLabel = new QLabel();
    //mousePointLabel->setText("");
    //mousePointLabel->setFixedWidth(100);

    //在状态栏增加控件
    //statusBar()->addPermanentWidget(statusLabel);
    //statusBar()->addPermanentWidget(mousePointLabel);

}

MainWindow::~MainWindow()
{
    delete ui;
}
/*
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    //获取点击位置坐标
    int x = event->x();
    int y = event->y();

    //坐标转换
    //openGLWidget->wcTOdc(x,y);

    //显示坐标信息
    statusBar()->showMessage("("+QString::number(x)+", "+QString :: number(y)+")");

}

void MainWindow::mousePressEvent(QMouseEvent *event)
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

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    //恢复鼠标形状
    QApplication::restoreOverrideCursor();

    //offset = event->pos()-offset;
    //从图到属性的查询返回什么信息？？
    int x = event->x();
    int y = event->y();
    //QPoint point(x,y);
    QPoint point = openGLWidget->wcTOdc(x,y);

    QString str = "("+QString :: number(point.x()) +", "+QString::number(point.y())+")";
    statusBar()->showMessage("position:" + str);
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *event)
{

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
*/
