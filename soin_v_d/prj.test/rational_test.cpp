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
    SUBCASE("Test operator +=") {
        Rational r1(1, 2);
        Rational r2(1, 3);
        r1 += r2;
        CHECK(r1.numer() == 5);
        CHECK(r1.denomer() == 6);
    }

    SUBCASE("Test operator -=") {
        Rational r1(1, 2);
        Rational r2(1, 3);
        r1 -= r2;
        CHECK(r1.numer() == 1);
        CHECK(r1.denomer() == 6);
    }

    SUBCASE("Test operator *=") {
        Rational r1(2, 3);
        Rational r2(3, 4);
        r1 *= r2;
        CHECK(r1.numer() == 1);
        CHECK(r1.denomer() == 2);
    }

    SUBCASE("Test operator /=") {
        Rational r1(2, 3);
        Rational r2(3, 4);
        r1 /= r2;
        CHECK(r1.numer() == 8);
        CHECK(r1.denomer() == 9);
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
TEST_CASE("Rational constructor") {
    SUBCASE("Test default constructor") {
        Rational r;
        CHECK(r.numer() == 0);
        CHECK(r.denomer() == 1);
    }

    SUBCASE("Test constructor with one argument") {
        Rational r(3);
        CHECK(r.numer() == 3);
        CHECK(r.denomer() == 1);
    }

    SUBCASE("Test constructor with two arguments") {
        Rational r(2, 3);
        CHECK(r.numer() == 2);
        CHECK(r.denomer() == 3);
        Rational f(2, 4);
        CHECK(f.numer() == 1);
        CHECK(f.denomer() == 2);
    }

}
TEST_CASE("Rational class operator overloading tests") {

    SUBCASE("Test assignment operator") {
        Rational a(2, 3);
        a = 5;
        CHECK(a == Rational(5, 1));
    }

    SUBCASE("Test addition-assignment operator") {
        Rational a(1, 3);
        a += 2;
        CHECK(a == Rational(7, 3));
    }

    SUBCASE("Test subtraction-assignment operator") {
        Rational a(4, 5);
        a -= 1;
        CHECK(a == Rational(-1, 5));
    }

    SUBCASE("Test multiplication-assignment operator") {
        Rational a(2, 3);
        a *= 3;
        CHECK(a == Rational(2, 1));
    }

    SUBCASE("Test division-assignment operator") {
        Rational a(7, 8);
        a /= 4;
        CHECK(a == Rational(7, 32));
    }

    SUBCASE("Test addition operator with integer on the right") {
        Rational a(1, 4);
        Rational b = a + 3;
        CHECK(b == Rational(13, 4));
    }

    SUBCASE("Test subtraction operator with integer on the right") {
        Rational a(5, 6);
        Rational b = a - 2;
        CHECK(b == Rational(-7, 6));
    }

    SUBCASE("Test multiplication operator with integer on the right") {
        Rational a(3, 7);
        Rational b = a * 2;
        CHECK(b == Rational(6, 7));
    }

    SUBCASE("Test division operator with integer on the right") {
        Rational a(2, 5);
        Rational b = a / 4;
        CHECK(b == Rational(1, 10));
    }

    SUBCASE("Test addition operator with integer on the left") {
        Rational a(1, 4);
        Rational b = 3 + a;
        CHECK(b == Rational(13, 4));
    }

    SUBCASE("Test subtraction operator with integer on the left") {
        Rational a(5, 6);
        Rational b = 2 - a;
        CHECK(b == Rational(7, 6));
    }

    SUBCASE("Test multiplication operator with integer on the left") {
        Rational a(3, 7);
        Rational b = 2 * a;
        CHECK(b == Rational(6, 7));
    }

    SUBCASE("Test division operator with integer on the left") {
        Rational a(2, 5);
        Rational b = 4 / a;
        CHECK(b == Rational(20, 2));
    }

    SUBCASE("Test stream input operator") {
        Rational a;
        std::stringstream input("2/3");
        input >> a;
        CHECK(a == Rational(2, 3));
        
    }

    SUBCASE("Test stream output operator") {
        Rational a(3, 4);
        std::stringstream output;
        output << a;
        CHECK(output.str() == "3/4");
    }
}