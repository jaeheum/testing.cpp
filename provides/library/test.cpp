#include "testing_v2/test.hpp"

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <tuple>
#include <vector>

#if __cpp_lib_source_location >= 201907L
void testing_v2::verify(bool ok, const std::source_location &location) {
  if (ok)
    return;
  fprintf(stderr,
          "FAIL %s:%d [%s]\n",
          location.file_name(),
          location.line(),
          location.function_name());
  exit(1);
}
#else
void testing_v2::verify(bool ok) {
  if (ok)
    return;
  fprintf(stderr, "FAIL\n");
  exit(1);
}
#endif

class testing_v2::Private::Static {
  friend int ::main();
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

testing_v2::Private::test_base_t::test_base_t() {
  Static::tests().push_back(this);
}

testing_v2::Private::test_base_t::~test_base_t() {
  auto &tests = Static::tests();
  auto it = std::find(tests.rbegin(), tests.rend(), this);
  if (it != tests.rend()) {
    std::swap(*it, tests.back());
    tests.pop_back();
  }
}

int main() {
  testing_v2::Private::Static::run_all();
  return 0;
}
