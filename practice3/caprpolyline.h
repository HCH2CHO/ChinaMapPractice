#ifndef CAPRPOLYLINE_H
#define CAPRPOLYLINE_H
#include "caprobject.h"

using namespace std;
class CAprPolyline : public CAprObject
{
public:
    CAprPolyline();
    virtual void Draw(QPainter &painter) const;
};

#endif // CAPRPOLYLINE_H
