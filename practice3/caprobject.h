#ifndef CAPROBJECT_H
#define CAPROBJECT_H

#include <QPainter>
#include <QVector>
#include <QPoint>

using namespace std;
class CAprObject
{
public:
    CAprObject();
    virtual ~CAprObject();
    QVector<QPoint> points;
    virtual void Draw(QPainter &painter) const{}
};

#endif // CAPROBJECT_H
