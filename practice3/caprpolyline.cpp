#include "caprpolyline.h"

CAprPolyline::CAprPolyline()
{

}

void CAprPolyline::Draw(QPainter& painter) const
{
    painter.drawPolyline(&points.at(0),points.size());
}
