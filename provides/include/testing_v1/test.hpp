#pragma once

#include "testing_v1/synopsis.hpp"

#include <utility>

namespace testing_v1 {

class test_private;

class test_base_t {
  friend class test_private;

  test_base_t(const test_base_t &) = delete;
  test_base_t &operator=(const test_base_t &) = delete;

  virtual void run() = 0;

protected:
  test_base_t();
  ~test_base_t() = default;
};

} // namespace testing_v1

template <class Action> struct testing_v1::test_t : test_base_t {
  test_t(Action &&action) : action(std::move(action)) {}
  test_t(const Action &action) : action(action) {}
  void run() override { action(); }

private:
  Action action;
};

template <class Action>
testing_v1::test_t<std::remove_cvref_t<Action>>
testing_v1::test(Action &&action) {
  return test_t<std::remove_cvref_t<Action>>(std::forward<Action>(action));
}
