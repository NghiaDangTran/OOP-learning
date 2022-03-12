#ifndef __REQUIRE_H
#define __REQUIRE_H

static int _Requirements, _Failures;

#undef assert
#define assert(predicate) { _Requirements++; if (!(predicate)) {fprintf(stderr, "-> FAIL line %d: %s\n", __LINE__, #predicate); _Failures++;} }

void __attribute__ ((destructor)) atend() {
  fprintf(stderr, "\n*** Program ended normally: %d requirements, %d failures.\n", _Requirements, _Failures);
}

#endif /* __REQUIRE_H */
