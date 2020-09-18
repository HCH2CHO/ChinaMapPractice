#ifndef CAPRMAP_H
#define CAPRMAP_H

#include <vector>
#include "caprlayer.h"
#include "caprmapattrb.h"
#include "caprcity.h"

using namespace std;
class CAprMap
{
public:
    CAprMap();
    ~CAprMap();
    int layerNum;
    QRect rect;
    vector<CAprLayer> layers;
    vector<CAprCity> cities;
};

#endif // CAPRMAP_H
