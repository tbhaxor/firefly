<br>

# Firefly [![Build Status](https://travis-ci.org/tbhaxor/firefly.svg?branch=master)](https://travis-ci.org/tbhaxor/firefly)


# Installation
1. Download the repository or clone
```
git clone https://github.com/tbhaxor/firefly.git
```
2. Change the directory to firefly
```
$ cd firefly
```
3. Copy the file named with `firefly` and `firefly.hpp` to the **includes** directory of your compiler

# Datatypes and classes
1. vector of `float` type
2. Vectors class of `firefly`

# Features
1. Addition of two vectors
2. Subtraction of two vectors
3.

# Example
Here I will demonstrate you a function to print vector components
**Note :** The following code will work if you have added both `firefly` and `firefly.hpp` to the **includes** directory of your compiler
```cpp
#include <firefly>
#include <iostream> // for io operations
#include <vector>  // for dynamic arrays :P
using namespace std;

int main() {
  vector<float> array = {1, 2, 3};
  Vectors vec1(array);  // Vectors is the class in firefly 
  vec1.print();   // print is the method of class
  return 0;
}
```
**OUTPUT**
```
[1, 2, 3, ]
```
 
