#ifndef CAPRFILELOAD_H
#define CAPRFILELOAD_H

#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "caprmap.h"
#include "caprpolygon.h"
#include "caprpolyline.h"
#include "caprlayerattrb.h"
#include "caprcity.h"

using namespace std;
class CAprFileload
{
public:
    CAprFileload();
    CAprMap* map;
    //CAprMapAttrb mapAttrb;
    //CAprCitySet citySet;
    void LoadtxtFile(const char*path);
    void LoaddataFile(const char*path);
    void LoadoptFile(const char*path);
private:
    static vector<string> split(const string str,char c);
    static float stringTofloat(const string& str);
    static int stringToint(const string& str);
    static long stringTolong(const string& str);
};

#endif // CAPRFILELOAD_H
