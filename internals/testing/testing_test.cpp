#include "testing_v1/test.hpp"

using namespace testing_v1;

auto dummy = test([]() { verify(1 == 1); });
