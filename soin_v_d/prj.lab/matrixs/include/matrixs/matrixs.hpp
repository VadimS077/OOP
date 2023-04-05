

#pragma once
#ifndef MATRIX_S
#define MATRIX_S

#include <tuple>
#include <stdexcept>

class MatrixS {
public:
    using SizeType = std::tuple<std::ptrdiff_t, std::ptrdiff_t>;

private:
    SizeType size_;
    int* data_;

public:
    explicit MatrixS(const SizeType& size = { 0, 0 });

    MatrixS(const std::ptrdiff_t m, const std::ptrdiff_t n);

    ~MatrixS();

    MatrixS(const MatrixS& other);

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

