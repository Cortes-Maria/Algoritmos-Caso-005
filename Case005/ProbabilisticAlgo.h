//
// Created by María José on 6/8/2020.
//

#ifndef CASE005_PROBABILISTICALGO_H
#define CASE005_PROBABILISTICALGO_H
#include "Intersection.h"
using namespace std;
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>

class ProbabilisticAlgo {
public:
    map<string,float> *distributionPercentage;
    map<int,set<string>> *numbersFormationTable;
    LinesDistribution *dist;
    vector<int> *existingDigits;
    map<int,int> *digitFrequency;

    ProbabilisticAlgo( LinesDistribution *pDist,map<int,set<string>> *pNumberTable){
        distributionPercentage = new map<string,float>();
        numbersFormationTable = pNumberTable;
        dist = pDist;
        existingDigits = new vector<int>();
        fillDistributionPercentage();
        digitFrequency = new map<int,int>();

    }

    void fillDistributionPercentage(){
        for(auto & it : dist->distributionMap){
            int percentage = (100*it.second)/dist->intersectionAmount;
            distributionPercentage->insert({it.first,percentage});
        }
    }
    void printDistPercetage(){
        for(auto & it : *distributionPercentage){
           cout<<it.first + " : ";
           cout<<it.second;
           cout<<"%"<<endl;
        }
    }
    void printExistingDigits(){
        for(auto & it : *existingDigits){
            cout<<it<<endl;
        }
    }

    void printDigitFrequency(){
        for(auto & it : *digitFrequency){
            cout<<it.first;
            cout<<" : ";
            cout<<it.second<<endl;
        }
    }



    void fillExistingDigits() {
        srand((unsigned) time(0));
         for(auto & it : *numbersFormationTable){
             int probability = sumProbability(it.second);
             int  randomNumber = (rand() % 100) + 1;
             if(1<=randomNumber && randomNumber<=probability){
                 existingDigits->push_back(it.first);
                 digitFrequency->at(it.first) +=1;//sumar a la frecuencia
                 printDigitFrequency();
             }
        }
    }
    int sumAppearance(){
        for(auto & it : *existingDigits){
            if(digitFrequency->find(it)!=digitFrequency->end()){
                digitFrequency->at(it)+=1;
            }
            else{
                digitFrequency->insert({it,1});
            }
        }
        existingDigits->clear();
    }

    int sumProbability(set<string> pIntersection){
        int result=0;
        for(const auto & it : pIntersection){
            if(distributionPercentage->find(it)!= distributionPercentage->end()){
                result += distributionPercentage->at(it);
            }
        }
        return result;
    }
};


#endif //CASE005_PROBABILISTICALGO_H
