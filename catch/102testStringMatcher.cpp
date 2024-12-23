#define CATCH_CONFIG_MAIN
#include "catch.hpp"

using namespace Catch::Matchers;

TEST_CASE("test string matcher", "[tag1]")
{
    CHECK_THAT("hello world", EndsWith("world" ) && !StartsWith("hello"));
    REQUIRE_THAT("hello new world", EndsWith("world" ) && StartsWith("hello"));
}


