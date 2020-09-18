#ifndef CAPRMAPATTRB_H
#define CAPRMAPATTRB_H

#include "caprlayerattrb.h"

using namespace std;
class CAprMapAttrb
{
public:
    CAprMapAttrb();
    int layerNum;
    vector<CAprLayerAttrb*> layerAttrbs;
private:
    void AddLayerAttrb();
};

#endif // CAPRMAPATTRB_H
