#include <catch2/catch_test_macros.hpp>
#include <string>

#include "validation.hpp"
#include "search.hpp"


// TEST_CASE MACRO (test_name, tags (optional))
TEST_CASE("Test Choice Key Invalid Argument", "[Key]") {
    REQUIRE(
        validation::choiceKey(
            "23kjh",
            0,
            22) == -1
    );
    REQUIRE(
        validation::choiceKey(
            "ddakjh12sds",
            0,
            22) == -1
    );
}

TEST_CASE("Test Choice Key Option Not Available", "[Key]") {
    REQUIRE(
        validation::choiceKey(
            "123",
            0,
            22) == -2
    );
}

TEST_CASE("Test Router", "[Router]") {
    REQUIRE(
        search::router(1) == search::ROUTE::EXIT_PROGRAM
    );
    REQUIRE(
        search::router(2) == search::ROUTE::SEARCH_TEXT_FILE
    );
}
