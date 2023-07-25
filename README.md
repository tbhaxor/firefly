# Firefly

This is a standalone C++ vector calculation library. It performs addition, subtraction, scalar multiplication, magnitude, normalisation, dot product, cross product, area of parallelogram, area of triangle, and angle between two vectors. The library supports both float and double precision and cuurrently it is only available on the CPU systems.

The library was designed to help people learn C++ and its concepts. It's a simple implementation, but it's a good place to start if you want to learn more about linear algebra and C++.

## Build and Install

> **Note** Ensure CMake 3.10+ and either Make or Ninja build systems are installed before following the steps.

1. Clone the repository
   ```console
   git clone --depth=1 --branch=master https://github.com/tbhaxor/firefly.git firefly
   ```

2. Configure the cmake build
   ```console
   cmake -Bbuild -DFirefly_ENABLE_EXAMPLES=ON -DFirefly_ENABLE_DOUBLE_PRECISION=ON
   ```

   The given CMake command allows you to enable the compilation of examples using double precision. To disable examples, you can either omit `-DFirefly_ENABLE_EXAMPLES=ON` or explicitly set it to `-DFirefly_ENABLE_EXAMPLES=OFF`. Additionally, if you prefer using single precision (float) instead of double precision, you can either omit `-DFirefly_ENABLE_DOUBLE_PRECISION=ON` or set it to `-DFirefly_ENABLE_DOUBLE_PRECISION=OFF`.

3. Build the code and install it
   ```console
   cmake --build build -j `nproc`
   sudo cmake --build build --target install/strip
   ```

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
   // returns Firefly::Vector type
   auto vec_addition = v1 + v2;
   
   // print out v1 on 
   std::cout << v1 << std::endl; // [1, 2, 3, 4]
   std::cout << v2 << std::endl; // [2, 3, 4, 1]
   std::cout << vec_addition << std::endl; // [3, 5, 7, 5]
}
```

### Build directly from compiler

```console
g++ main.cpp -lfirefly -o mycode
./mycode
```

### Build using `CMake`

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