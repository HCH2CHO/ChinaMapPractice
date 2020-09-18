#include "caprlayer.h"

CAprLayer::CAprLayer()
{

}

void CAprLayer::Draw(QPainter &painter)
{
    //若面封闭
    if(layerAttrb.isClose == 1)
    {
        //填充颜色
        QBrush brush(layerAttrb.areaColor,Qt::SolidPattern);
        painter.setBrush(brush);

        //判断线型
        if(layerAttrb.lineType == 1)
        {
            QPen pen(layerAttrb.lineColor,layerAttrb.lineWidth*30000);
            painter.setPen(pen);
        }
    }
    else
    {
        QPen pen(layerAttrb.lineColor,layerAttrb.lineWidth*30000);
        painter.setPen(pen);
    }
    //分别绘制每个目标
    for(vector<CAprObject*>::iterator it = objects.begin();it!=objects.end();it++)
    {
        (*it)->Draw(painter);
    }
}
