

#pragma once
#ifndef MATRIX_S
#define MATRIX_S

#include <tuple>
#include <stdexcept>

class MatrixS {
public:
    using SizeType = std::tuple<std::ptrdiff_t, std::ptrdiff_t>;

private:
    SizeType size_ = { 0,0 };
    int** matrix=nullptr;
    std::ptrdiff_t r=0;
    std::ptrdiff_t c=0;


public:
    MatrixS()=default;
    explicit MatrixS(const SizeType& size);

    MatrixS(const std::ptrdiff_t m, const std::ptrdiff_t n);

    ~MatrixS();

    MatrixS(const MatrixS& other);
    void newmem();

    MatrixS& operator=(const MatrixS& other);
    int& at(const SizeType& elem);
    const int& at(const SizeType& elem) const;
    int& at(const std::ptrdiff_t i, const std::ptrdiff_t j);
    const int& at(const std::ptrdiff_t i, const std::ptrdiff_t j) const;

    void resize(const SizeType& new_size);
    void resize(const std::ptrdiff_t i, const std::ptrdiff_t j);
    const SizeType& ssize() const noexcept;
    std::ptrdiff_t nRows() const noexcept;
    std::ptrdiff_t nCols() const noexcept;
};
#endif

