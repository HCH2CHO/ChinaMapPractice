#include "caprpolygon.h"

CAprPolygon::CAprPolygon()
{

}

void CAprPolygon::Draw(QPainter &painter) const
{
    painter.drawPolygon(&points.at(0),points.size());
}

