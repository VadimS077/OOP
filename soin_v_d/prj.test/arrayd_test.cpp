#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include <arrayd/arrayd.hpp>
TEST_CASE("ArrayD") {
    SUBCASE("Default constructor") {
        ArrayD a;
        CHECK(a.getsize() == 0);
    }

    SUBCASE("Resize and subscript operator") {
        ArrayD a;
        a.resize(5);
        a[0] = 3.5;
        a[1] = 2.0;
        CHECK(a.getsize() == 5);
        CHECK(a[0] == doctest::Approx(3.5));
        CHECK(a[1] == doctest::Approx(2.0));
    }

    SUBCASE("Copy constructor") {
        ArrayD a;
        a.resize(5);
        a[0] = 3.5;
        ArrayD b(a);
        CHECK(b.getsize() == 5);
        CHECK(b[0] == doctest::Approx(3.5));
        b[0] = 1.0;
        CHECK(a[0] == doctest::Approx(3.5));
        CHECK(b[0] == doctest::Approx(1.0));
    }

    SUBCASE("Insert and remove") {
        ArrayD a(2);
        a.insert(0, 1.5);
        a.insert(1, 2.5);
        a.insert(1, 2.0);
        CHECK(a.getsize() == 5);
        CHECK(a[0] == doctest::Approx(1.5));
        CHECK(a[1] == doctest::Approx(2.0));
        CHECK(a[2] == doctest::Approx(2.5));
        a.remove(1);
        CHECK(a.getsize() == 4);
        CHECK(a[0] == doctest::Approx(1.5));
        CHECK(a[1] == doctest::Approx(2.5));
    }

    SUBCASE("Assignment operator") {
        ArrayD a(2);
        a[0] = 1.5;
        a[1] = 2.5;
        ArrayD b(3);
        b[0] = 3.5;
        b[1] = 4.5;
        b[2] = 5.5;
        b = a;
        CHECK(b.getsize() == 2);
        CHECK(b[0] == doctest::Approx(1.5));
        CHECK(b[1] == doctest::Approx(2.5));
    }

    SUBCASE("Output stream operator") {
        ArrayD a(3);
        a[0] = 1.5;
        a[1] = 2.5;
        a[2] = 3.5;
        std::ostringstream oss;
        oss << a;
        CHECK(oss.str() == "[1.5, 2.5, 3.5]");
    }
}
