#include "testing_v2/test.hpp"

using namespace testing_v2;

static void function() { verify(1 != 2); }

auto function_test = test(function);
