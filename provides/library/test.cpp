#include "testing_v1/test.hpp"

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <tuple>
#include <vector>

void testing_v1::verify(bool ok) {
  if (ok)
    return;
  fprintf(stderr, "FAIL\n");
  exit(1);
}

class testing_v1::Private::Static {
  friend void run_all();
  friend class test_base_t;

  using tests_t = std::vector<test_base_t *>;

  static tests_t &tests() {
    static tests_t tests;
    return tests;
  }

  static void run_all() {
    for (auto test : tests())
      test->run();
  }
};

void testing_v1::run_all() { Private::Static::run_all(); }

testing_v1::Private::test_base_t::test_base_t() {
  Static::tests().push_back(this);
}

testing_v1::Private::test_base_t::~test_base_t() {
  auto &tests = Static::tests();
  auto it = std::find(tests.rbegin(), tests.rend(), this);
  if (it != tests.rend()) {
    std::swap(*it, tests.back());
    tests.pop_back();
  }
}

int main() {
  testing_v1::run_all();
  return 0;
}
