#include <iostream>
#include <firefly.hpp>
#include <vector>

using namespace std;

int main()
{
    vector<float> v1 = {1,
                        2,
                        3,
                        4};
    vector<float> v2 = {2,
                        4,
                        6,
                        8};

    Vectors vector1(v1);
    Vectors vector2(v2);

    vector1.add(vector2).print();

    cout << endl;

    vector1.add(vector2).scalorMultiply(4.5).print();

    return 0;
}
