#include <iostream>
#include <vector>
#include <cassert>
#include "../src/firefly"
using namespace std;

int main()
{
    vector<float> var1 = {3.029, 1.879};
    vector<float> var2 = {0.825, 2.036};
    Vectors vec1(var1);
    Vectors vec2(var2);
    Vectors v;
    vec1.print();
    vec2.print();

    cout << endl;
    vec2.print();
    cout << endl;
    Vectors v2 = vec1.componentParallelTo(vec2);
    v2.print();
    cout << vec1.areaOfParallelogramWith(vec2) << endl;
    cout << vec1.areaOfTriangleWith(vec2) << endl;
    return 0;
}
