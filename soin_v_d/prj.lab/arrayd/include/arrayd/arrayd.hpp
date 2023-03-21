// DynArray.h : включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта.

#pragma once
#ifndef ARRAYD_H
#define ARRAYD_H

#include <iosfwd>




class ArrayD {
public:

	ArrayD();
	ArrayD(const ArrayD& rhs);
	ArrayD(const ptrdiff_t cap);
	~ArrayD();
	ptrdiff_t getsize() const;
	void insert(ptrdiff_t i,double a);
	void remove(ptrdiff_t i);
	void resize(const ptrdiff_t newsize);
	double& operator[](const ptrdiff_t i);
	const double& operator[](const ptrdiff_t i) const;
	std::ostream& writeto(std::ostream& ostrm) const;
	ArrayD& operator=(const ArrayD& rhs);
	
public:
	ptrdiff_t size_;
	double* arr;
	ptrdiff_t capacity;

};

std::ostream& operator<<(std::ostream& ostrm, const ArrayD& rhs);
#endif