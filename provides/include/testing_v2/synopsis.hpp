#pragma once

#if __cplusplus >= 202002L && __has_include(<source_location>)
#include <source_location>
#endif

#include "testing_v2/private.hpp"

// test.hpp ====================================================================

/// A minimalist test framework.
namespace testing_v2 {

/// Holds a registered test action and should only be used at namespace scope.
template <class Action> struct test_t : Private::test_t<Action> {
  /// Constructs a test from the given action.
  template <class ForwardableAction> test_t(ForwardableAction &&action);

  /// Tests are not CopyConstructible.
  test_t(const test_t &) = delete;

  /// Tests are not CopyAssignable.
  test_t &operator=(const test_t &) = delete;
};

/// Creates and registers a test action and should only be used at namespace
/// scope.
template <class Action> test_t<std::decay_t<Action>> test(Action &&action);

/// Prints `FAIL` and `exit(1)`s the program if the result is false.
#if __cpp_lib_source_location >= 201907L
void verify(
    bool result,
    const std::source_location &location = std::source_location::current());
#else
void verify(bool result);
#endif

} // namespace testing_v2

/// Runs all registered test actions.  Usually there should only be a single
/// test action per test program.
int main();
