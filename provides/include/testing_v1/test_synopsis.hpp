#pragma once

#include "polyfill_v1/type_traits.hpp"

namespace testing_v1 {

struct test_base_t;

template <class Action> struct test_t;

template <class Action>
test_t<std::remove_cvref_t<Action>> test(Action &&action);

void verify(bool result);

} // namespace testing_v1
