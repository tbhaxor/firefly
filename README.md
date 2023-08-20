# Firefly

<p align="center">
   <a href="https://www.producthunt.com/posts/libfirefly?utm_source=badge-featured&utm_medium=badge&utm_souce=badge-libfirefly" target="_blank"><img src="https://api.producthunt.com/widgets/embed-image/v1/featured.svg?post_id=406416&theme=light" alt="LibFirefly - A&#0032;standalone&#0032;C&#0043;&#0043;&#0032;Library&#0032;for&#0032;vectors&#0032;calculations | Product Hunt" style="width: 250px; height: 54px;" width="250" height="54" /></a>
</p>

This is a standalone C++ vector calculation library. It performs addition, subtraction, scalar multiplication, magnitude, normalisation, dot product, cross product, area of parallelogram, area of triangle, and angle between two vectors. The library supports both float and double precision and cuurrently it is only available on the CPU systems.

The library was designed to help people learn C++ and its concepts. It's a simple implementation, but it's a good place to start if you want to learn more about linear algebra and C++.

## Supported Platforms and Compilers

**Linux** GCC v9+ or Clang v11+ <br>
**MacOS** GCC v10+ or Clang v12+ <br>

## Build and Install

> **Note** Ensure CMake 3.10+ and either Make or Ninja build systems are installed before following the steps.

1. Clone the repository
   ~~~console
   git clone --depth=1 --branch=master https://github.com/tbhaxor/firefly.git firefly
   ~~~

2. Configure the cmake build
   ~~~console
   cmake -Bbuild -DFirefly_ENABLE_EXAMPLES=ON
   ~~~

   <center>

   | CMake Options | Type | Description |
   | :-----------: | :--: | :---------- |
   | Firefly_ENABLE_EXAMPLES | Boolean | Adds the `examples/` directory in the compile target. (default: `OFF`) |
   | Firefly_ENABLE_DOUBLE_PRECISION | Boolean | Enables `double` type instead of `float` when enabled. (default: `ON`) |
   | Firefly_ENABLE_TESTS | Boolean | Download gtest and configures it to enable test. Check [Testing](#testing) section below. (default: `OFF`) |

   </center>
   
3. Build the code and install it
   ~~~console
   cmake --build build -j `nproc`
   sudo cmake --build build --target install/strip
   ~~~

## Testing

By default tests are disabled, you can enable them with `-DFirefly_ENABLE_TESTS` and run using ctest, as shown below.

~~~console
cmake -Bbuild -DCMAKE_BUILD_TYPE=Debug -DFirefly_ENABLE_TESTS=ON
cmake --build build 
ctest --test-dir build/tests --verbose
~~~

> **Note** If you are using `ASSERT_NEAR` in your test cases, I advice using `Firefly_TEST_EPSILON` macro defined [here](tests/CMakeLists.txt#L5).

## Example Usage

~~~c++
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
~~~

### Build directly from compiler

~~~console
g++ main.cpp -lfirefly -o mycode
./mycode
~~~

Or with double precision

~~~console
g++ main.cpp -DDOUBLE_PRECISION=1 -lfirefly -o mycode
./mycode
~~~

### Build using `CMake`

~~~cmake
target_link_libraries(${PROJECT_NAME} PUBLIC firefly)
~~~

## Future Plans

- Implement Kokkos for HPC platforms

## Contact

Email: tbhaxor _at_ proton _dot_ me <br />
Twitter: @tbhaxor <br />
LinkedIn: @tbhaxor 
