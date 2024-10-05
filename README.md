# Firefly

Firefly is a header-only standalone C++ vector calculation library. It performs basic arithmetic operations on vectors and introduces utility functions for advanced functionalities. The library supports templates with arithmetic type precision, and currently, it is only available on CPU systems.

The library was designed to help people learn C++ and its concepts. It's a simple implementation, but it's a good place to start if you want to learn more about linear algebra and C++

## Features

Firefly is loaded with a bunch of cool features designed to make your vector calculations a breeze:

### Core Features

- **Header-Only:** Simply include the header files and you're good to go! No need to worry about linking libraries.
- **Template Support:** Works seamlessly with various arithmetic types (e.g., int, float, double) and even complex numbers (std::complex).
- **Arithmetic Operations** Perform basic arithmetic operations like addition, subtraction, and scaling on your vectors effortlessly.

### Advanced Functionalities

- Geometric Calculations: Compute dot products, cross products (for 3D vectors), and easily normalize vectors.
- Utility Functions:
  - Determine the angle between two vectors.
  - Check if vectors are parallel, anti-parallel, or orthogonal.
  - Calculate the area of a parallelogram or triangle formed by two vectors.
  - Project or reject a vector onto or from another vector.
  - Compute the Euclidean distance between two vectors.
  - Reflect a vector across another vector.
  - Rotate a 2D vector by a specified angle.
  - Calculate the scalar projection of a vector onto another vector.
  - Perform linear interpolation (Lerp) between two vectors.

## Supported Compilers and Standard

- GCC v13+ with c++-23
- LLVM v16+ with c++-23

## Build and Install

> [!Note]
> Ensure CMake 3.10+ and either Make or Ninja build systems are installed before following the steps.

1. Clone the repository

   ```console
   git clone --depth=1 --branch=master https://github.com/tbhaxor/firefly.git firefly
   ```

2. Configure the cmake build

   ```console
   cmake -Bbuild -DFirefly_ENABLE_EXAMPLES=ON
   ```

   <center>

   |      CMake Options      |  Type   | Description                                                                                                |
   | :---------------------: | :-----: | :--------------------------------------------------------------------------------------------------------- |
   | Firefly_ENABLE_EXAMPLES | Boolean | Adds the `examples/` directory in the compile target. (default: `OFF`)                                     |
   |  Firefly_ENABLE_TESTS   | Boolean | Download gtest and configures it to enable test. Check [Testing](#testing) section below. (default: `OFF`) |

   </center>

3. Build the code and install it
   ```console
   cmake --build build
   sudo cmake --install build
   ```

## Testing

By default tests are disabled, you can enable them with `-DFirefly_ENABLE_TESTS` and run using ctest, as shown below.

```console
cmake -Bbuild -DCMAKE_BUILD_TYPE=Debug -DFirefly_ENABLE_TESTS=ON
cmake --build build
ctest --test-dir build/tests --verbose
```

## Example Usage

```cpp
#include <iostream>
#include <firefly/utilities.hpp>
#include <firefly/vector.hpp>

int main() {
  firefly::vector<int, 2> v1{1, 2};
  firefly::vector<int, 2> v2{-8, 6};
  auto v3 = v1 + v2;
  firefly::vector<std::complex<int>, 5> v4{{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}};
  auto v5 = v4.as_type<int>();

  std::cout << v1 << std::endl;
  std::cout << v2 << std::endl;
  std::cout << v3 << std::endl;
  std::cout << v4 << std::endl;
  std::cout << v5 << std::endl;
  std::cout << v1.norm() << std::endl;
  std::cout << v1.to_normalized().norm() << std::endl;
  std::cout << firefly::utilities::vector::angle_between(v1, v2) << std::endl
            << std::boolalpha << firefly::utilities::vector::are_orthogonal(v1, v2) << std::endl
            << firefly::utilities::vector::are_parallel(v1, v1) << std::endl
            << firefly::utilities::vector::are_anti_parallel(v1, -v1) << std::endl
            << std::noboolalpha;
}
```

## Future Plans

- Implement Kokkos for HPC platforms

## Scope of Contribution

- First of all, if you can help me implement [future plans](#future-plans), I would be thankful to you
- Documentation using doxygen. I am new to it, you may help me add more professional documentation
- Add more test cases. I may have left some of the edge cases that you might have come across.

## Contact

Twitter: @tbhaxor <br />
LinkedIn: @tbhaxor
