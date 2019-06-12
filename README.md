<br>

# Firefly [![Build Status](https://travis-ci.org/tbhaxor/firefly.svg?branch=master)](https://travis-ci.org/tbhaxor/firefly)

> A standalone C++ Library for vectors calculations

# Installation

1. Download the repository or clone
   ```sh
   git clone https://github.com/tbhaxor/firefly.git
   ```
2. Change the directory to firefly
   ```sh
   cd firefly
   ```
3. Make a build directory
   ```sh
   mkdir build
   ```
4. Configure the Project
   ```sh
   cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr
   ```
5. Make the package
   ```sh
   make
   ```
6. Install the package
   ```sh
   sudo make install
   ```
7. Copy the file(s) from `INCLUDES` directory to `/usr/include`

# Datatypes and classes

1. vector of `float` type
2. Vectors class of `firefly`

# Features

1. Addition of two vectors
2. Subtraction of two vectors
3. Scalor Multiplication of the floating number with Vector
4. Find vector magnitude
5. Find normalized form of the vector i.e unit vector
6. Find dot product of two vectors
7. Find cross product of two vectors
8. Find area of parallelogram formed by two vectors
9. Find area of triangle formed by two vectors
10. Find angle between two vector in _degrees_ or _radians_
11. Check whether the two vectors are parallel to each other or not
12. Check whether the two vectors are orthogonal to each other or not
13. Find a component of vector parallel to base vector while vector projection
14. Find a component of vector orthogonal to base vector while vector projection

<!--# Overview of the methods
NOTE: `float` is an inbuilt datatype in c++ and Vectors is the class in `firefly`

| Class Method | Arguments | Return Type |              Description               |
|--------------|-----------|-------------|----------------------------------------|
| add          | Vectors   | Vectors     | This method takes a Vectors class type |

-->

# Example

Here I will demonstrate you a function to print vector components <br>
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

# CONTRIBUTION

To contribute open a Pull Request from new branch

# Contact Me

[![fb](https://img.shields.io/badge/FaceBook-gurkirat.py-blue.svg)](https://fb.com/gurkirat.py) [![gh](https://img.shields.io/badge/GitHub-tbhaxor-orange.svg)](https://github.com/tbhaxor) [![mail](https://img.shields.io/badge/Email%20Address-tbhaxor@gmail.com-green.svg)](mailto:tbhaxor@gmail.com)
