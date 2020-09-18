#ifndef CAPRPOLYGON_H
#define CAPRPOLYGON_H
#include "caprobject.h"

using namespace std;
class CAprPolygon : public CAprObject
{
public:
    CAprPolygon();
    virtual void Draw(QPainter &painter) const;
};

#endif // CAPRPOLYGON_H
