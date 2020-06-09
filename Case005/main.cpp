#include <iostream>
#include "Intersection.h"

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
    dist->printInfo();

    return 0;
}