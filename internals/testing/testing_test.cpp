#include "testing_v1/test.hpp"

using namespace testing_v1;

auto test_lambda = test([]() { verify(1 == 1); });

static void function() { verify(1 != 2); }

auto test_function = test(function);
