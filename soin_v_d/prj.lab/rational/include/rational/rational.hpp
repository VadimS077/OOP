// Copyright 2023 by Polevoy Dmitry under Free Public License 1.0.0

#pragma once
#ifndef RATIONAL_RATIONAL_HPP_20230215
#define RATIONAL_RATIONAL_HPP_20230215

#include <iosfwd>
#include <cstdint>
class Rational {



public:
	Rational();
	Rational(const Rational&) = default;
	Rational(Rational&&) = default;
	explicit Rational(int32_t n) noexcept;
	Rational(int32_t n, int32_t d);
	int32_t nod(int32_t num, int32_t denom);
	Rational& reducing();
	bool zero();
	bool negative();
	bool positive();
	int32_t numer();
	int32_t denomer();

public:
	Rational& operator=(const Rational& rhs);
	Rational& operator+=(const Rational& rhs);
	Rational& operator-=(const Rational& rhs);
	Rational& operator*=(const Rational& rhs);
	Rational& operator/=(const Rational& rhs);
	
	std::ostream& writeto(std::ostream& ostrm) const;
	std::istream& readfrom(std::istream& istrm);
	
	Rational& operator++();
	Rational operator++(int32_t);
	Rational& operator--();
	Rational operator--(int32_t);
	Rational operator+();
	Rational operator-();
	Rational& operator=(const int32_t& rhs);
	Rational& operator+=(const int32_t& rhs);
	Rational& operator-=(const int32_t& rhs);
	Rational& operator*=(const int32_t& rhs);
	Rational& operator/=(const int32_t& rhs);

private:
	int32_t num;
	int32_t denom;
	static const char sep = '/';







};
bool operator==(Rational lhs, const Rational& rhs);
bool operator>(Rational lhs, const Rational& rhs);
bool operator<(Rational lhs, const Rational& rhs);
bool operator!=(const Rational& lhs, const Rational& rhs);
bool operator<=(const Rational& lhs, const Rational& rhs);
bool operator>=(const Rational& lhs, const Rational& rhs);

Rational operator+(Rational lhs, const Rational& rhs);
Rational operator-(Rational lhs, const Rational& rhs);
Rational operator*(Rational lhs, const Rational& rhs);
Rational operator/(Rational lhs, const Rational& rhs);

Rational operator+(Rational lhs, const int32_t& rhs);
Rational operator-(Rational lhs, const int32_t& rhs);
Rational operator*(Rational lhs, const int32_t& rhs);
Rational operator/(Rational lhs, const int32_t& rhs);

Rational operator+(const int32_t& lhs, Rational rhs);
Rational operator-(const int32_t& lhs, Rational rhs);
Rational operator*(const int32_t& lhs, Rational rhs);
Rational operator/(const int32_t& lhs, Rational rhs);

std::istream& operator>>(std::istream& istrm, Rational& rat);
std::ostream& operator<<(std::ostream& ostrm, const Rational& rat);


#endif