#include <assert.h>

#define REQUIRE(assertion, what) \
    if (!(assertion)) _assert (what, __FILE__, __LINE__)

#define ENSURE(assertion, what) \
    if (!(assertion)) _assert (what, __FILE__, __LINE__)
