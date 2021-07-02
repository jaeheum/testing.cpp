#include "testing_v2/test.hpp"

using namespace testing_v2;

auto lambda_test = test([]() { verify(1 == 1); });
