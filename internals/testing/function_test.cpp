#include "testing_v1/test.hpp"

using namespace testing_v1;

static void function() { verify(1 != 2); }

auto function_test = test(function);
