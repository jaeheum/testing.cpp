#pragma once

#include "testing_v1/synopsis.hpp"

#include <utility>

template <class Action>
template <class ForwardableAction>
testing_v1::Private::test_t<Action>::test_t(ForwardableAction &&action)
    : action(std::forward<ForwardableAction>(action)) {}

template <class Action> void testing_v1::Private::test_t<Action>::run() {
  action();
}

template <class Action>
template <class ForwardableAction>
testing_v1::test_t<Action>::test_t(ForwardableAction &&action)
    : Private::test_t<Action>(std::forward<ForwardableAction>(action)) {}

template <class Action>
testing_v1::test_t<std::decay_t<Action>> testing_v1::test(Action &&action) {
  return test_t<std::decay_t<Action>>(std::forward<Action>(action));
}
