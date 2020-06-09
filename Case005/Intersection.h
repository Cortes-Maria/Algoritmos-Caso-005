//
// Created by ixel on 8/6/20.
//

#ifndef CASE005_INTERSECTION_H
#define CASE005_INTERSECTION_H
#include "Line.h"
#include <list>
#include <map>
#include <iostream>
#include <algorithm>
#include <vector>

#define maxY 119
#define maxX 1079

class LinesDistribution{
public:
    int intersectionAmount;
    map<string, int> distributionMap;
    vector<Line*> lines; //todas las lineas

    LinesDistribution(){
        intersectionAmount = 0;
        distributionMap = map<string,int>();
        lines = vector<Line*>();
    }

    void insertLines(vector<Line*> pLines){
        for(Line* line : pLines){
            lines.push_back(line);
            for(Line* line2 : lines){
                if(isIntersection(line,line2)){ //asks if there is an intersection
                    intersectionAmount++;
                    setIntersectionType(line,line2);
                }
            }
        }
    }


    bool isIntersection(Line *pLine1, Line *pLine2){
        if(pLine1->lineType == pLine2->lineType){ //same kinda line
            return false;
        }else{
            float intX; //Intersection in X
            if(pLine1->lineType == "H" && pLine2->lineType == "V"){
                return true;
            }else if(pLine2->lineType == "H" && pLine1->lineType == "V"){
                return true;
            }else{ //they both have y = mx+b, y = b or x = a, does not matter
                intX = (pLine2->b - pLine1->b)/(pLine1->m-pLine2->m);
                if(intX <= maxX){ //que no se salga de X
                    if((pLine1->m*intX + pLine1->b) <= maxY){ //que no se salga de Y
                        if((pLine1->m*intX + pLine1->b) == ((pLine2->m * intX) + pLine2->b)){ //que sí intersequen
                            return true;
                        }
                    }
                }
                return false;
            }
        }
    }

    void setIntersectionType(Line *pLine1, Line *pLine2){
        if(distributionMap.find(getIntersectionType(pLine1,pLine2)) != distributionMap.end()){
            distributionMap.find(getIntersectionType(pLine1,pLine2))->second++;
        }else{
            distributionMap.insert(pair<string,int>(getIntersectionType(pLine1,pLine2),1));
        }
    }

    string getIntersectionType(Line *pLine1, Line *pLine2) {
        if (((pLine1->lineType == "H") && (pLine2->lineType == "V")) ||
            ((pLine2->lineType == "H") && (pLine1->lineType == "V"))) {
            return "HV";
        } else if ((pLine1->lineType == "I" && pLine2->lineType == "D") ||
                   (pLine1->lineType == "D" && pLine2->lineType == "I")) {
            return "ID";
        } else if (((pLine1->lineType == "V") && pLine2->lineType == "I") ||
                   (pLine1->lineType == "I" && (pLine2->lineType == "V"))) {
            return "VI";
        } else if (((pLine1->lineType == "V") && pLine2->lineType == "D") ||
                   (pLine1->lineType == "D" && (pLine2->lineType == "V"))) {
            return "VD";
        } else if (((pLine1->lineType == "H") && pLine2->lineType == "I") ||
                   (pLine1->lineType == "I" && (pLine2->lineType == "H"))) {
            return "HI";
        } else if (((pLine1->lineType == "H") && pLine2->lineType == "D") ||
                   (pLine1->lineType == "D" && (pLine2->lineType == "H"))) {
            return "HD";
        } else {
            return "NI";
        }
    }

    void printInfo(){
        cout<<"Total intersections: "<<intersectionAmount<<endl;
        map<string, int>::iterator it;
        for (it = distributionMap.begin(); it != distributionMap.end(); it++){
            cout << it->first << " : " << it->second<<endl;
        }
    }
};

#endif //CASE005_INTERSECTION_H
