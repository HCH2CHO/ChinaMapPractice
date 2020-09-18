#ifndef MYVIEW_H
#define MYVIEW_H
#include <QGraphicsView>

using namespace std;
class MyGraphicsView : public QGraphicsView
{
public:
    explicit MyGraphicsView(QWidget *parent=0);
};
#endif // MYVIEW_H
