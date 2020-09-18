#include "caprfileload.h"

CAprFileload::CAprFileload()
{
    map = new CAprMap;

}

//分割读取的一行字符串
vector<string> CAprFileload::split(const string str,char c)
{
    vector<string> strs;
    int start = 0;
    int len = str.length();
    int pos;
    while(start < len)
    {
        pos = str.find(c,start);
        if(pos > 0)
        {
            strs.push_back(str.substr(start,pos-start));
            start = pos+1;
        }
        else
        {
            strs.push_back(str.substr(start,pos-start));
            break;
        }
    }

    return strs;
}

//字符串转浮点
float CAprFileload::stringTofloat(const string& str)
{
    istringstream iss(str);
    float num;
    iss >> num;
    return num;
}

//字符串转整型
int CAprFileload::stringToint(const string& str)
{
    istringstream iss(str);
    int num;
    iss >> num;
    return num;
}

//字符串转长整型
long CAprFileload::stringTolong(const string& str)
{
    istringstream iss(str);
    long num;
    iss >> num;
    return num;
}

void CAprFileload::LoaddataFile(const char*path)
{
    string str;
    ifstream fin(path, ios::in);
    if(!fin)
    {
        printf("The File is not exist!");
        return;
    }

    //读取最小外接矩形
    long x1,x2,y1,y2;
    getline(fin,str);
    vector<string> strs1 = split(str,',');
    x1 = stringTolong(strs1.at(0));
    y1 = stringTolong(strs1.at(1));
    getline(fin,str);
    vector<string> strs2 = split(str,',');
    x2 = stringTolong(strs2.at(0));
    y2 = stringTolong(strs2.at(1));
    map->rect.setTopLeft(QPoint(x1,y1));
    map->rect.setBottomRight(QPoint(x2,y2));

    //读取图层数量
    int layerNum;
    getline(fin,str);
    layerNum = stringToint(str);
    map->layerNum = layerNum;
    //cout<<map->layerNum<<endl;

    for(int i = 0;i < layerNum;i++)
    {
        CAprLayer layer;

        //读取层名大小，不存储
        getline(fin,str);

        //读取层名
        getline(fin,str);
        layer.layerName = str;

        //读取目标数量
        getline(fin,str);
        int objNum = stringToint(str);
        layer.objNum = objNum;

        for(int k = 0;k < objNum;k++)
        {
            CAprObject* object = NULL;

            //读取目标类型
            getline(fin,str);
            int objType;
            objType = stringToint(str);

            //判断目标类型
            if(objType == 1)
            {
                object = new CAprPolyline;
            }
            else
            {
                object = new CAprPolygon;
            }

            //读取坐标点信息
            while(true)
            {
                long x,y;
                getline(fin,str);
                vector<string> strs3 = split(str,',');
                x = stringTolong(strs3.at(0));
                y = stringTolong(strs3.at(1));
                if((x == -99999)&&(y == -99999))
                   break;
                QPoint point(x,y);
                object->points.push_back(point);
            }
            layer.objects.push_back(object);
        }
        map->layers.push_back(layer);

        }
    fin.close();
}

void CAprFileload::LoadoptFile(const char*path)
{
    string str;
    ifstream fin(path, ios::in);
    if(!fin)
    {
        printf("The File is not exist!");
        return;
    }

    //读取图层数目
    getline(fin,str);
    int layerNum = stringToint(str);
    //cout<<layerNum<<endl;

    for(int i =0;i < layerNum;i++)
    {
        CAprLayerAttrb layerAttrb;

        //读取层名
        getline(fin,str);
        string layerName = str;
        layerAttrb.layerName = layerName;

        //读取线型
        getline(fin,str);
        int lineType = stringToint(str);
        layerAttrb.lineType = lineType;

        //判断线型为0（面）
        if(lineType == 0)
        {
            //读取面是否封闭
            getline(fin,str);
            layerAttrb.isClose = stringToint(str);

            //读取面的填充颜色
            getline(fin,str);
            vector<string> str1 = split(str,',');
            QColor areaColor(stringToint(str1.at(0)),stringToint(str1.at(1)),stringToint(str1.at(2)));
            layerAttrb.areaColor= areaColor;

            //将图层绘制信息和图层联系起来
            for(vector<CAprLayer>::iterator it = map->layers.begin();it != map->layers.end();it++)
            {
                if((*it).layerName == layerAttrb.layerName)
                {
                    (*it).layerAttrb = layerAttrb;
                    break;
                }
            }
        }
        //判断线型为1（线）
        else
        {
            //读取线宽
            getline(fin,str);
            layerAttrb.lineWidth = stringTofloat(str);

            //读取线的颜色
            getline(fin,str);
            vector<string> str2 = split(str,',');
            QColor lineColor(stringToint(str2.at(0)),stringToint(str2.at(1)),stringToint(str2.at(2)));
            layerAttrb.lineColor= lineColor;

            //读取面是否封闭
            getline(fin,str);
            int isClose = stringToint(str);
            layerAttrb.isClose = isClose;
            if(isClose == 0)
            {
                for(vector<CAprLayer>::iterator it = map->layers.begin();it != map->layers.end();it++)
                {
                    if((*it).layerName == layerAttrb.layerName)
                    {
                        (*it).layerAttrb = layerAttrb;
                        break;
                    }
                }
            }
            else
            {
                //读取面的填充颜色
                getline(fin,str);
                vector<string> str3 = split(str,',');
                QColor areaColor(stringToint(str3.at(0)),stringToint(str3.at(1)),stringToint(str3.at(2)));
                layerAttrb.areaColor = areaColor;

                for(vector<CAprLayer>::iterator it = map->layers.begin();it != map->layers.end();it++)
                {
                     if((*it).layerName == layerAttrb.layerName)
                     {
                         (*it).layerAttrb = layerAttrb;
                         break;
                     }
                }
            }
        }
    }

    fin.close();
}

void CAprFileload::LoadtxtFile(const char*path)
{
    string str;
    ifstream fin(path, ios::in);
    if(!fin)
    {
        printf("The File is not exist!");
        return;
    }

    while(getline(fin,str))
    {
        CAprCity city;
        long x,y;
        vector<string> strs = split(str,' ');

        //读取省会名称
        city.name = strs.at(0);
        //cout<<city.name<<endl;

        //读取坐标
        x = stringTolong(strs.at(1));
        y = stringTolong(strs.at(2));
        QPoint point(x,y);
        city.point = point;

        map->cities.push_back(city);
    }
    fin.close();
}

