// DynArray.h : включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта.

#pragma once
#ifndef ARRAYD_H
#define ARRAYD_H

#include <iosfwd>
#include <cstddef>




class ArrayD {
public:

	ArrayD()=default;
	ArrayD(const ArrayD& rhs);
	explicit ArrayD(const std::ptrdiff_t cap);
	~ArrayD();
	std::ptrdiff_t ssize() const noexcept;
	void insert(std::ptrdiff_t i,double a);
	void remove(std::ptrdiff_t i);
	void resize(const std::ptrdiff_t newsize);
	double& operator[](const std::ptrdiff_t i);
	const double& operator[](const std::ptrdiff_t i) const;
	std::ostream& writeto(std::ostream& ostrm) const;
	ArrayD& operator=(const ArrayD& rhs);
	
public:
	std::ptrdiff_t size_=0;
	double* arr=nullptr;
	std::ptrdiff_t capacity=0;
};

std::ostream& operator<<(std::ostream& ostrm, const ArrayD& rhs);
#endif