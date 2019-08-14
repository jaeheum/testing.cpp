# [≡](#contents) [Testing.C++](#) [![Gitter](https://badges.gitter.im/per-framework/community.svg)](https://gitter.im/per-framework/community) [![Build Status](https://travis-ci.org/per-framework/testing.cpp.svg?branch=v1)](https://travis-ci.org/per-framework/testing.cpp) [![Code Coverage](https://img.shields.io/codecov/c/github/per-framework/testing.cpp/v1.svg)](https://codecov.io/gh/per-framework/testing.cpp/branch/v1)

Minimalist C++ test definition framework.

```c++
#include "testing_v1/test.hpp"

using namespace testing_v1;

auto a_test = test([]() { verify(1 + 1 == 2); });
```

See [`synopsis.hpp`](provides/include/testing_v1/synopsis.hpp) for the API.
