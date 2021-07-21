# [≡](#contents) [Testing.C++](#) [![Gitter](https://badges.gitter.im/per-framework/community.svg)](https://gitter.im/per-framework/community) [![Build Status](https://travis-ci.org/per-framework/testing.cpp.svg?branch=v2)](https://travis-ci.org/per-framework/testing.cpp) [![Code Coverage](https://img.shields.io/codecov/c/github/per-framework/testing.cpp/v2.svg)](https://codecov.io/gh/per-framework/testing.cpp/branch/v2)

Minimalist C++ test definition framework.

```c++
#include "testing_v2/test.hpp"

using namespace testing_v2;

auto a_test = test([]() { verify(1 + 1 == 2); });
```

See [`synopsis.hpp`](provides/include/testing_v2/synopsis.hpp) for the API.

## changes from v1

- no longer `requires`
  [polyfill.cpp](https://github.com/per-framework/polyfill.cpp)
- prints failure locations with a c++20 compiler that features
  `<source_location>` c.f.
  [https://en.cppreference.com/w/cpp/compiler_support](https://en.cppreference.com/w/cpp/compiler_support)

```
1/3 Test #1: fail_test ........................***Failed    0.00 sec
FAIL [void function_will_fail()] /home/foo/bar/fail_test.cpp:5 
...
```
