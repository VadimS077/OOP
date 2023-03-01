#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include <rational/rational.hpp>

TEST_CASE("Rational arithmetic") {
    Rational a(3, 4);
    Rational b(1, 2);

    SUBCASE("Addition") {
        Rational c = a + b;
        CHECK(c.numer() == 5);
        CHECK(c.denomer() == 4);
    }

    SUBCASE("Subtraction") {
        Rational c = a - b;
        CHECK(c.numer() == 1);
        CHECK(c.denomer() == 4);
    }
    SUBCASE("increment") {
        a++;
        CHECK(a.numer() == 7);
        CHECK(a.denomer() == 4);
    }
    SUBCASE("decrement") {
        a--;
        CHECK(a.numer() == -1);
        CHECK(a.denomer() == 4);
    }
    SUBCASE("unarplus") {
        Rational x = +a;
        CHECK(x.numer() == 3);
        CHECK(x.denomer() == 4);
    }
    SUBCASE("unarminus") {
        Rational x = -a;
        CHECK(x.numer() == -3);
        CHECK(x.denomer() == 4);
    }

    SUBCASE("Multiplication") {
        Rational c = a * b;
        CHECK(c.numer() == 3);
        CHECK(c.denomer() == 8);
    }

    SUBCASE("Division") {
        Rational c = a / b;
        CHECK(c.numer() == 3);
        CHECK(c.denomer() == 2);
    }
}

TEST_CASE("Rational comparison") {
    Rational a(3, 4);
    Rational b(1, 2);
    Rational c(3, 4);

    CHECK(a != b);
    CHECK(a == c);
    CHECK(b < a);
    CHECK(b <= a);
    CHECK(a > b);
    CHECK(a >= b);
}