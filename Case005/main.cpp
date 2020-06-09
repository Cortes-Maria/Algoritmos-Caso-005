#include <iostream>
#include <set>
#include "Intersection.h"
#include "ProbabilisticAlgo.h"
#define totalCorridas 500
int main() {
    Line *l1 = new Line(-1,-1,0,1);
    //cout<<l1->lineType<<endl;
    Line *l2 = new Line(0,1,5,0);
    //cout<<l2->lineType<<endl;
    Line *l3 = new Line(0,2,2,2);
    //cout<<l3->lineType<<endl;
    Line *l4 = new Line(2,0,2,2);
    //cout<<l4->lineType<<endl;

    vector<Line*> lines = vector<Line*>();
    lines.push_back(l1);
    lines.push_back(l2);
    lines.push_back(l3);
    lines.push_back(l4);

    LinesDistribution *dist = new LinesDistribution();
    dist->insertLines(lines);

    map<int,set<string>> *NumbersTable = new map<int,set<string>>();
    NumbersTable->insert({0,{"HV"}});
    NumbersTable->insert({1, {"VI"}});
    NumbersTable->insert({2,{"HI"}});
    NumbersTable->insert({3,{"ID"}});
    NumbersTable->insert({4,{"HI","HV","VI"}});
    NumbersTable->insert({5,{"HV","VD","HD"}});
    NumbersTable->insert({6,{"ID","HI","HD"}});
    NumbersTable->insert({7,{"HI"}});
    NumbersTable->insert({8,{"HI","HD","ID"}});
    NumbersTable->insert({9,{"ID","HD","HI"}});

    ProbabilisticAlgo prueba = ProbabilisticAlgo(dist,NumbersTable);
    cout<<"Intersection distribution"<<endl;
    prueba.printDistPercetage();
    prueba.fillExistingDigits();
    cout<<""<<endl;
    cout<<"Existing digits"<<endl;
    prueba.printExistingDigits();





    return 0;
}