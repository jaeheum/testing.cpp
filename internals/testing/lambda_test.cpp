#include "testing_v1/test.hpp"

using namespace testing_v1;

auto lambda_test = test([]() { verify(1 == 1); });
