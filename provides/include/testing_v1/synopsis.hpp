#pragma once

#include "polyfill_v1/type_traits.hpp"

namespace testing_v1 {

// test.hpp ====================================================================

/// Holds a registered test action and should only be used at namespace scope.
template <class Action> struct test_t;

/// Creates and registers a test action and should only be used at namespace
/// scope.
template <class Action>
test_t<std::remove_cvref_t<Action>> test(Action &&action);

/// Prints `FAIL` and `exit(1)`s the program if the result is false.
void verify(bool result);

} // namespace testing_v1
