// Copyright 2023 by ??? under Free Public License 1.0.0

#include <rational/rational.hpp>
#include <iostream>
#include <cassert>





Rational::Rational() {
	num = 0;
	denom = 1;
}
Rational::Rational(int32_t n) noexcept {
	num = n;
	denom = 1;
}
Rational::Rational(int32_t n, int32_t d) {
	if (d < 0) {
		d *= -1;
		n *= -1;
	}
	if (d == 0) {
		throw std::invalid_argument("division by zero");
	}
	assert(d != 0);
	num = n;
	denom = d;
	reducing();
}
int32_t Rational::numer() {
	return num;
}
int32_t Rational::denomer() {
	return denom;
}


int32_t Rational::nod(int32_t n, int32_t d) {
	if (d == 0) {
		throw std::invalid_argument("division by zero");
	}
	assert(d != 0);
	while (d != 0) {
		int32_t temp = d;
		d = n % d;
		n = temp;
	}
	return std::abs(n);
}
Rational& Rational::reducing() {
	int32_t dev = nod(num, denom);
	num /= dev;
	denom /= dev;
	return *this;
}
Rational& Rational::operator=(const Rational& rhs) {
	num = rhs.num;
	denom = rhs.denom;
	reducing();
	return *this;
}
Rational& Rational::operator+=(const Rational& rhs) {
	num = num * rhs.denom + rhs.num * denom;
	denom = denom * rhs.denom;
	reducing();
	return *this;
}
Rational& Rational::operator-=(const Rational& rhs) {
	num = num * rhs.denom - rhs.num * denom;
	denom = denom * rhs.denom;
	reducing();
	return *this;
}
Rational& Rational::operator*=(const Rational& rhs) {
	num = num * rhs.num;
	denom = denom * rhs.denom;
	reducing();
	return *this;
}
Rational& Rational::operator/=(const Rational& rhs) {
	num = num * rhs.denom;
	denom = denom * rhs.num;

	reducing();
	return *this;
}

Rational& Rational::operator=(const int32_t& rhs) {
	return *this = Rational(rhs);
}
Rational& Rational::operator+=(const int32_t& rhs) {
	return *this += Rational(rhs);
}
Rational& Rational::operator-=(const int32_t& rhs) {
	return *this -= Rational(rhs);
}
Rational& Rational::operator*=(const int32_t& rhs) {
	return *this *= Rational(rhs);
}
Rational& Rational::operator/=(const int32_t& rhs) {
	return *this /= Rational(rhs);
}


Rational operator+(Rational lhs, const Rational& rhs) {
	lhs += rhs;
	lhs.Rational::reducing();
	return lhs;
}
Rational operator-(Rational lhs, const Rational& rhs) {
	lhs -= rhs;
	lhs.Rational::reducing();
	return lhs;
}
Rational operator*(Rational lhs, const Rational& rhs) {
	lhs *= rhs;
	lhs.Rational::reducing();
	return lhs;
}
Rational operator/(Rational lhs, const Rational& rhs) {
	lhs /= rhs;
	lhs.Rational::reducing();
	return lhs;
}
Rational operator+(Rational lhs, const int32_t& rhs) {
	lhs += Rational(rhs);
	return lhs;
}
Rational operator-(Rational lhs, const int32_t& rhs) {
	lhs -= Rational(rhs);
	return lhs;
}
Rational operator*(Rational lhs, const int32_t& rhs) {
	lhs *= Rational(rhs);
	return lhs;
}
Rational operator/(Rational lhs, const int32_t& rhs) {
	lhs /= Rational(rhs);
	return lhs;
}

Rational operator+(const int32_t& lhs, Rational rhs) {
	rhs += lhs;
	return rhs;
}
Rational operator-(const int32_t& lhs, Rational rhs) {
	rhs -= lhs;
	return -rhs;
}
Rational operator*(const int32_t& lhs, Rational rhs) {
	rhs *= lhs;
	return rhs;
}
Rational operator/(const int32_t& lhs, Rational rhs) {
	rhs/=lhs;
	Rational a(1);
	rhs = a / rhs;

	return rhs;
}


bool Rational::zero() {
	return num == 0;
}
bool Rational::negative() {
	return num < 0;
}
bool Rational::positive() {
	return num > 0;
}
bool operator==(Rational lhs, const Rational& rhs) {
	Rational res = lhs - rhs;

	return res.Rational::zero();
}
bool operator>(Rational lhs, const Rational& rhs) {
	Rational res = lhs - rhs;
	return res.Rational::positive();
}
bool operator<(Rational lhs, const Rational& rhs) {
	Rational res = lhs - rhs;
	return res.Rational::negative();
}
bool operator!=(const Rational& lhs, const Rational& rhs) {
	return !operator==(lhs, rhs);
}
bool operator<=(const Rational& lhs, const Rational& rhs) {
	return !operator>(lhs, rhs);
}
bool operator>=(const Rational& lhs, const Rational& rhs) {
	return !operator<(lhs, rhs);
}
Rational& Rational::operator++() {
	*this += 1;
	return *this;
}
Rational Rational::operator++(int32_t) {
	Rational tmp(*this);
	num += denom;
	return tmp;
}
Rational& Rational::operator--() {
	*this -= 1;
	return *this;
}
Rational Rational::operator--(int32_t) {
	Rational tmp(*this);
	num -= denom;
	return tmp;
}
Rational Rational::operator+() {
	return *this;
}
Rational Rational::operator-() {
	Rational a(-1);
	*this *= a;
	return *this;
}

std::ostream& operator<<(std::ostream& ostrm, const Rational& rat) {
	return rat.WriteTo(ostrm);
}
std::ostream& Rational::WriteTo(std::ostream& ostrm) const noexcept {
	ostrm << num << sep << denom;
	if (denom == 0) {
		throw std::invalid_argument("division by zero");
	}
	assert(denom != 0);

	return ostrm;


}
std::istream& operator>>(std::istream& istrm, Rational& rat) {
	return rat.ReadFrom(istrm);
}
std::istream& Rational::ReadFrom(std::istream& istrm) {
	int32_t numerator, denominator;
	char separator;
	istrm >> numerator >> separator >> denominator;
	if (!istrm.fail() && separator == Rational::sep && denominator != 0) {
		num = numerator;
		denom = denominator;
	}
	else {
		istrm.setstate(std::ios_base::failbit);
	}
	return istrm;
}


