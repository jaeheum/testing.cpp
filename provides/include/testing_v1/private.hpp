#pragma once

#include "polyfill_v1/type_traits.hpp"
#include <utility>

namespace testing_v1 {

template <class Action> struct test_t;

void run_all();

class Private {
  friend void run_all();
  template <class> friend struct test_t;

  class Static;

  class test_base_t;
  template <class Action> class test_t;
};

} // namespace testing_v1

class testing_v1::Private::test_base_t {
  friend class Static;
  template <class> friend class test_t;

  ~test_base_t();
  test_base_t();

  virtual void run() = 0;
};

template <class Action> class testing_v1::Private::test_t : test_base_t {
  friend class Static;
  template <class> friend struct testing_v1::test_t;

  template <class ForwardableAction> test_t(ForwardableAction &&action);

  void run() override;

  std::conditional_t<std::is_function_v<Action>, Action *, Action> action;
};
