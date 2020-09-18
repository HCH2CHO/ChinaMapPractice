#ifndef CAPRLAYER_H
#define CAPRLAYER_H

#include <QPainter>
#include <QWidget>
#include <string>
#include <vector>
#include "caprobject.h"
#include "caprlayerattrb.h"

using namespace std;
class CAprLayer
{
public:
    CAprLayer();
    int layerNameSize;
    string layerName;
    int objNum;
    CAprLayerAttrb layerAttrb;
    vector<CAprObject*> objects;
    void Draw(QPainter& painter);
};

#endif // CAPRLAYER_H
