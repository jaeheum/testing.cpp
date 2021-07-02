#pragma once

#include <utility>

int main();

namespace testing_v2 {

template <class Action> struct test_t;

class Private {
  friend int ::main();
  template <class> friend struct test_t;

  class Static;

  class test_base_t;
  template <class Action> class test_t;
};

} // namespace testing_v2

class testing_v2::Private::test_base_t {
  friend class Static;
  template <class> friend class test_t;

  ~test_base_t();
  test_base_t();

  virtual void run() = 0;
};

template <class Action> class testing_v2::Private::test_t : test_base_t {
  friend class Static;
  template <class> friend struct testing_v2::test_t;

  template <class ForwardableAction> test_t(ForwardableAction &&action);

  void run() override;

  Action action;
};
