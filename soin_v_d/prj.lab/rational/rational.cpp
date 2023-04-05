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

	return ostrm;


}
std::istream& operator>>(std::istream& istrm, Rational& rat) {
	return rat.ReadFrom(istrm);
}
std::istream& Rational::ReadFrom(std::istream& istrm)
{
	char sym('-');
	while (std::isspace(istrm.peek())) {
		sym = istrm.get();
	}
	int32_t numInp_(0);
	int32_t denomInp_(0);
	sym = '-';
	bool isNeg(false);
	if (istrm.peek() == '-') {
		isNeg = true;
		sym = istrm.get();
	}

	while (std::isdigit(istrm.peek())) {
		sym = istrm.get();
		numInp_ *= 10;
		numInp_ += static_cast<int>(sym - '0');
	}
	if (sym == '-') {
		istrm.setstate(std::ios_base::failbit);
		return istrm;
	}

	if (istrm.peek() != '/') {
		istrm.setstate(std::ios_base::failbit);
		return istrm;
	}
	sym = istrm.get();

	while (std::isdigit(istrm.peek())) {
		sym = istrm.get();
		denomInp_ *= 10;
		denomInp_ += static_cast<int>(sym - '0');
	}
	if (sym == '/') {
		istrm.setstate(std::ios_base::failbit);
		return istrm;
	}

	if (istrm.good() || istrm.eof()) {
		if (denomInp_ == 0) {
			istrm.setstate(std::ios_base::failbit);
			return istrm;
		}
		num = numInp_;
		denom = denomInp_;
		if (isNeg) {
			num *= -1;
		}
		reducing();
	}
	return istrm;
}