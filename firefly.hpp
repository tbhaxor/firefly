#ifndef FIREFLY_H
#define FIREFLY_H

#include <iostream>
#include <vector>
using namespace std;

class Vectors {
  public:
    vector<float> vec;
    Vectors(vector<float> vector);
    void zeroVector(int len);
    void print();
    bool emptyVector();
    Vectors addWith(Vectors v);
};

#endif