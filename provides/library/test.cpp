#include "testing_v1/test.hpp"

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

using tests_t = std::vector<testing_v1::test_base_t *>;

static tests_t &tests() {
  static tests_t tests;
  return tests;
}

testing_v1::test_base_t::test_base_t() { tests().push_back(this); }

int main() {
  for (auto test : tests())
    test->run();

  return 0;
}
