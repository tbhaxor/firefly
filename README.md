# Firefly

This is a standalone C++ vector calculation library. It performs addition, subtraction, scalar multiplication, magnitude, normalisation, dot product, cross product, area of parallelogram, area of triangle, and angle between two vectors. The library supports both float and double precision and cuurrently it is only available on the CPU systems.

The library was designed to help people learn C++ and its concepts. It's a simple implementation, but it's a good place to start if you want to learn more about linear algebra and C++.

## Example Usage

```c++
#include <iostream>
#include <vector>

#include <firefly/vector.hpp>

int main() {
   // define two vectors
   std::vector<Real> vec1{1, 2, 3, 4};
   std::vector<Real> vec2{2, 3, 4, 1};

   // define firefly vectors from std::vector
   Firefly::Vector v1(vec1);
   Firefly::Vector v2(vec2);

   // add two firefly vectors and 
   // returns unique_ptr of Firefly::Vector type
   std::unique_ptr<Firefly::Vector> vec_addition = v1 + v2;
   
   // print out v1 on 
   std::cout << v1 << std::endl; // [1, 2, 3, 4]
   std::cout << v2 << std::endl; // [2, 3, 4, 1]
   std::cout << *vec_addition << std::endl; // [3, 5, 7, 5]
}
```

### Using `CMake`

```cmake
# for shared linking
target_link_libraries(${PROJECT_NAME} PUBLIC Firefly::Shared)

# for static linking
target_link_libraries(${PROJECT_NAME} PUBLIC Firefly::Static)
```

## Future Plans

- Implement Kokkos for HPC platforms

## Contact

Email: tbhaxor@proton.me <br />
Twitter: @tbhaxor <br />
LinkedIn: @tbhaxor 