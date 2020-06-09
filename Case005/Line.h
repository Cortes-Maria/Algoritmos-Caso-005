//
// Created by ixel on 8/6/20.
//

#ifndef CASE005_LINE_H
#define CASE005_LINE_H
#include <math.h>
#include <stdio.h>
#include <string>

#define PI 3.14159265
using namespace std;

class Point{
public:
    int x,y;

    Point(){
        x = y = 0;
    }

    Point(int pX, int pY){
        x = pX;
        y = pY;
    }

};

class Line{
public:
    Point *origin;
    Point *destiny;
    float m; //slope
    float b; //y-intercept
    string lineType;

    Line(){
        origin = nullptr;
        destiny = nullptr;
        m = b = 0;
        lineType = "";
    }

    Line(int xO, int yO, int xD, int yD){
        origin = new Point(xO, yO);
        destiny = new Point(xD, yD);

        if((xO-xD) == 0){//isVertical
            // y = b
            lineType = "V";
            m = 0;
            b = 0;
        }else if((yO-yD) == 0){ //isHorizontal
            // x = a
            lineType = "H";
            m = 0;
            b = yO;
        }else{
            // y = mx + b

            m = (yO-yD)/(xO-xD);
            if((m>=tan(0) && m<tan(PI/8) || (m>=tan((7*PI)/8) && m<tan(PI)))){
                lineType = "H";
            }else if(m>=tan(PI/8) && m<tan((3*PI)/8)){
                lineType = "I";
            }else if(m>=tan((3*PI)/8) && m<tan((5*PI)/8)){
                lineType = "V";
            }else if(m>=tan((5*PI)/8) && m<tan((7*PI)/8)){
                lineType = "D";
            }else{
                lineType = "H";
            }
            b = yO - m*xO;
        }
    }
};

#endif //CASE005_LINE_H
