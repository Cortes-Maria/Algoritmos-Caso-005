//
// Created by María José on 6/8/2020.
//

#ifndef CASE005_PROBABILISTICALGO_H
#define CASE005_PROBABILISTICALGO_H
#include "Intersection.h"
using namespace std;
#include <iostream>

class ProbabilisticAlgo {
public:
    map<string,float> *distributionPercentage;
    map<int,map<string,bool>> *numbersFormationTable;
    LinesDistribution *dist;

    ProbabilisticAlgo( LinesDistribution *pDist,map<int,map<string,bool>> *pNumberTable){
        distributionPercentage = new map<string,float>();
        numbersFormationTable = pNumberTable;
        dist = pDist;
        fillDistributionPercentage();
    }

    void fillDistributionPercentage(){
        for(auto it = dist->distributionMap.begin(); it != dist->distributionMap.end(); it++){
            float percentage = (100*it->second)/dist->intersectionAmount;
            distributionPercentage->insert({it->first,percentage});
        }
    }
    void printDistPercetage(){
        for(auto it = distributionPercentage->begin(); it != distributionPercentage->end(); it++){
           cout<<it->first + " : ";
           cout<<it->second;
           cout<<"%"<<endl;
        }
    }
};


#endif //CASE005_PROBABILISTICALGO_H
