#ifndef CAPRCITYSET_H
#define CAPRCITYSET_H

#include <vector>
#include "caprcity.h"

using namespace std;

class CAprCitySet
{
public:
    CAprCitySet();
    vector<CAprCity> cities;
    void Draw();
};

#endif // CAPRCITYSET_H
