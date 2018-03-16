#ifndef FIREFLY_H
#define FIREFLY_H

#include <iostream>
#include <vector>
using namespace std;

class Vectors {
  public:
    vector<float> vec;
    Vectors(vector<float> vector);
    Vectors();
    void print();
    Vectors add(Vectors v);
    Vectors subtract(Vectors v);
    Vectors scalorMultiply(float number);
    float magnitude();
    Vectors normalize();
    float dotProductWith(Vectors v);
    float angleWith(Vectors v, bool degree);
};

#endif