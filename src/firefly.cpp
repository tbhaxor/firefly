#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include "./firefly.hpp"
using namespace std;

Vectors::Vectors() {}

Vectors::Vectors(vector<float> vec) {
    this->vec = vec;
}

void Vectors::print() {
    cout<<"[ ";
    for(int i = 0 ;i < vec.size(); ++i) {
        cout<<vec[i]<<", ";
    }
    cout<<"]";
}

Vectors Vectors::add(Vectors v) {
    if (this->vec.size() != v.vec.size()) {
        cout << "Exception: Vectors size don't match";
        exit(1);
    }
    vector<float> tmp;
    for(int i = 0; i < this->vec.size(); ++i) {
        tmp.push_back(this->vec[i] + v.vec[i]);
    }
    return Vectors(tmp);
}

Vectors Vectors::subtract(Vectors v) {
    if (this->vec.size() != v.vec.size()) {
        cout << "Exception: Vectors size don't match";
        exit(1);
    }
    vector<float> tmp;
    for (int i = 0; i < this->vec.size(); ++i) {
        tmp.push_back(this->vec[i] - v.vec[i]);
    }
    return Vectors(tmp);
}

Vectors Vectors::scalorMultiply(float number) {
    if (number == 0.0f) {
        cout << "Exception: Zero Divide Error";
        exit(1);
    }
    vector<float> tmp;
    for (int i = 0; i < this->vec.size(); ++i) {
        tmp.push_back(this->vec[i] * number);
    }
    return Vectors(tmp);
}

float Vectors::magnitude() {
    // this the method 1
    float dot = this->dotProductWith(Vectors(this->vec));
    return sqrt(dot);
    // this the second way
    // float sum = 0;
    // for(int i = 0; i < this->vec.size(); i++) {
    //     sum += pow(this->vec[i], 2);
    // }
    // return sqrt(sum);
}

Vectors Vectors::normalize() {
    float mag = this->magnitude();
    if (mag == 0.0f) {
        cout<<"Exception: Zero Divide Error";
        exit(1);
    }
    vector<float> n;
    for(int i = 0; i < this->vec.size(); ++i) {
        n.push_back(this->vec[i] / mag);
    }

    return Vectors(n);
}

float Vectors::dotProductWith(Vectors v) {
    float sum = 0.0f;
    if(this->vec.size() != v.vec.size()) {
        cout<<"Exception: Vectors size don't match";
        exit(1);
    }
    for(int i = 0; i < this->vec.size(); ++i) {
        sum += this->vec[i] * v.vec[i];
    }
    return sum;
}

float Vectors::angleWith(Vectors v, bool degree = false) {
    // this is the first method
    float dot = this->dotProductWith(v);
    float mag1 = this->magnitude();
    float mag2 = v.magnitude();
    float radians = acos(dot / (mag1 * mag2));
    if(degree) {
        return radians * (180.0 / M_PI);
    }
    return radians;

    // this is the second way, not working giving NaN
    // Vectors v1 = this->normalize();
    // Vectors v2 = v.normalize();
    // float dot = v1.dotProductWith(v2);
    // float radians = acos(dot);
    // if(degree) {
    //     return radians * (180.0 / M_PI);
    // }
    // return radians;
}

bool Vectors::isParallelWith(Vectors v) {
    if(this->magnitude() == 0 or v.magnitude() == 0) {
        return true;
    }
    return this->angleWith(v) == 180.0 or this->angleWith(v) == 0.0;
}

bool Vectors::isOrthogonalWith(Vectors v) {
    if (this->magnitude() == 0 or v.magnitude() == 0) {
        return true;
    }
    return this->angleWith(v, true) == 90;
}

Vectors Vectors::componentParallelTo(Vectors b) {
    Vectors u = b.normalize();
    float dot = this->dotProductWith(u);
    return Vectors(u.scalorMultiply(dot));
}

Vectors Vectors::componentOrthogonalTo(Vectors v) {
    Vectors p = this->componentParallelTo(v);
    return Vectors(this->subtract(p));
}

Vectors Vectors::crossProductWith(Vectors v) {
    float x1, x2, y1, y2, z1 = 0, z2 = 0;
    x1 = this->vec[0];
    x2 = v.vec[0];
    y1 = this->vec[1];
    y2 = v.vec[1];
    if(this->vec.size() == 3 and v.vec.size() == 3) {
        z1 = this->vec[2];
        z2 = v.vec[2];
    }

    vector<float> new_vector = {
        y1 * z2 - y2 * z1,
        -(x1 * z2 - x2 * z1),
        x1 * y2 - x2 * y1
    };
    
    return Vectors(new_vector);
}

float Vectors::areaOfParallelogramWith(Vectors v) {
    return this->crossProductWith(v).magnitude();
}

float Vectors::areaOfTriangleWith(Vectors v) {
    return this->areaOfParallelogramWith(v) / 2;
}

bool Vectors::isEqualTo(Vectors v) {
    return this->vec == v.vec;
}