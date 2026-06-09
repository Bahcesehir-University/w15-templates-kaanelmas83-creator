// ============================================================================
//  test.cpp  -  Catch2 tests for the Templates lab
//  Groups are tagged [group1]..[group6] so they can be run independently:
//      ./test_bin [group1]
//  This enables per-section partial grading.
// ============================================================================

#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"

// Pull in the student's code. Rename their main so it does not clash with
// Catch2's generated main().
#define main student_main
#include "MainProgram.cpp"
#undef main

#include <string>
#include <stdexcept>

// ---------------------------------------------------------------------------
// Group 1: Basic function template  ->  maxValue
// ---------------------------------------------------------------------------
TEST_CASE("Group 1 - maxValue basic", "[group1]") {
    REQUIRE(maxValue(3, 7) == 7);
    REQUIRE(maxValue(7, 3) == 7);
}

TEST_CASE("Group 1 - maxValue with doubles", "[group1]") {
    REQUIRE(maxValue(2.5, 1.5) == Catch::Approx(2.5));
    REQUIRE(maxValue(1.5, 2.5) == Catch::Approx(2.5));
}

TEST_CASE("Group 1 - maxValue equal values", "[group1]") {
    REQUIRE(maxValue(5, 5) == 5);
}

// ---------------------------------------------------------------------------
// Group 2: Multiple type parameters  ->  addValues
// ---------------------------------------------------------------------------
TEST_CASE("Group 2 - addValues same type", "[group2]") {
    REQUIRE(addValues(2, 3) == 5);
}

TEST_CASE("Group 2 - addValues mixed types promotes to double", "[group2]") {
    REQUIRE(addValues(2, 3.5) == Catch::Approx(5.5));
    REQUIRE(addValues(1.25, 2) == Catch::Approx(3.25));
}

TEST_CASE("Group 2 - addValues negative", "[group2]") {
    REQUIRE(addValues(-4, 4) == 0);
}

// ---------------------------------------------------------------------------
// Group 3: Class template  ->  Pair
// ---------------------------------------------------------------------------
TEST_CASE("Group 3 - Pair getters", "[group3]") {
    Pair<int, double> p(7, 2.5);
    REQUIRE(p.getFirst() == 7);
    REQUIRE(p.getSecond() == Catch::Approx(2.5));
}

TEST_CASE("Group 3 - Pair setters", "[group3]") {
    Pair<int, int> p(1, 2);
    p.setFirst(10);
    p.setSecond(20);
    REQUIRE(p.getFirst() == 10);
    REQUIRE(p.getSecond() == 20);
}

TEST_CASE("Group 3 - Pair swapValues same type", "[group3]") {
    Pair<int, int> p(1, 2);
    p.swapValues();
    REQUIRE(p.getFirst() == 2);
    REQUIRE(p.getSecond() == 1);
}

// ---------------------------------------------------------------------------
// Group 4: Generic container  ->  Box
// ---------------------------------------------------------------------------
TEST_CASE("Group 4 - Box add and size", "[group4]") {
    Box<int> b;
    REQUIRE(b.size() == 0);
    b.add(1); b.add(2);
    REQUIRE(b.size() == 2);
}

TEST_CASE("Group 4 - Box get and total", "[group4]") {
    Box<int> b;
    b.add(10); b.add(20); b.add(30);
    REQUIRE(b.get(0) == 10);
    REQUIRE(b.get(2) == 30);
    REQUIRE(b.total() == 60);
}

TEST_CASE("Group 4 - Box out of range throws", "[group4]") {
    Box<int> b;
    b.add(5);
    REQUIRE_THROWS_AS(b.get(3), std::out_of_range);
}

TEST_CASE("Group 4 - Box works with double", "[group4]") {
    Box<double> b;
    b.add(1.5); b.add(2.5);
    REQUIRE(b.total() == Catch::Approx(4.0));
}

// ---------------------------------------------------------------------------
// Group 5: Template specialization  ->  describe
// ---------------------------------------------------------------------------
TEST_CASE("Group 5 - describe generic returns 1", "[group5]") {
    REQUIRE(describe(42) == 1);
    REQUIRE(describe(3.14) == 1);
}

TEST_CASE("Group 5 - describe string specialization", "[group5]") {
    REQUIRE(describe(std::string("hi")) == 4);   // 2 + length(2)
    REQUIRE(describe(std::string("")) == 2);      // 2 + length(0)
}

// ---------------------------------------------------------------------------
// Group 6: Non-type template parameter  ->  FixedArray
// ---------------------------------------------------------------------------
TEST_CASE("Group 6 - FixedArray capacity", "[group6]") {
    FixedArray<int, 4> fa;
    REQUIRE(fa.capacity() == 4);
}

TEST_CASE("Group 6 - FixedArray default initialized", "[group6]") {
    FixedArray<int, 3> fa;
    REQUIRE(fa.at(0) == 0);
    REQUIRE(fa.at(2) == 0);
}

TEST_CASE("Group 6 - FixedArray set and at", "[group6]") {
    FixedArray<int, 3> fa;
    fa.set(1, 99);
    REQUIRE(fa.at(1) == 99);
}

TEST_CASE("Group 6 - FixedArray out of range throws", "[group6]") {
    FixedArray<int, 2> fa;
    REQUIRE_THROWS_AS(fa.set(5, 1), std::out_of_range);
    REQUIRE_THROWS_AS(fa.at(-1), std::out_of_range);
}
