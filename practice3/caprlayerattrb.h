#ifndef CAPRLAYERATTRB_H
#define CAPRLAYERATTRB_H

#include <stdio.h>
#include <string>
#include <QColor>

using namespace std;
class CAprLayerAttrb
{
public:
    CAprLayerAttrb();
    string layerName;
    bool lineType;  //线型，1为线型，0为空线（面），无外观
    float lineWidth;  //线宽
    QColor lineColor; //线的颜色
    bool isClose;  //判断面是否封闭
    QColor areaColor; //面的填充颜色
};

#endif // CAPRLAYERATTRB_H
