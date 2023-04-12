#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include<matrixs/matrixs.hpp>


TEST_CASE("MatrixS tests") {
    SUBCASE("Default constructor") {
        MatrixS mat;
        CHECK(mat.ssize() == std::make_tuple(0, 0));
    }

    SUBCASE("Size constructor") {
        MatrixS::SizeType s = std::make_tuple(2, 3);
        MatrixS mat(3,2);
        CHECK(mat.ssize() == std::make_tuple(3, 2));
        CHECK(mat.nRows() == 3);
        CHECK(mat.nCols() == 2);
    }

    SUBCASE("Copy constructor") {
        MatrixS mat(2, 3);
        mat.at(0, 0) = 1;
        MatrixS copy(mat);
        CHECK(copy.ssize() == std::make_tuple(2, 3));
        CHECK(copy.at(0, 0) == 1);
    }

    SUBCASE("Assignment operator") {
        MatrixS mat1(2, 3);
        mat1.at(0, 0) = 1;
        MatrixS mat2;
        mat2 = mat1;
        CHECK(mat2.ssize() == std::make_tuple(2, 3));
        CHECK(mat2.at(0, 0) == 1);
    }

    SUBCASE("Resize") {
        MatrixS mat(6, 6);
        mat.at(1, 2) = 6;
        mat.resize(2, 3);
        CHECK(mat.ssize() == std::make_tuple(2, 3));
        CHECK(mat.nRows() == 2);
        CHECK(mat.nCols() == 3);
        CHECK(mat.at(1,2)==6);
        CHECK(mat.at(1,1) == 0);


    }

    SUBCASE("At") {
        MatrixS mat(2, 3);
        mat.at(0, 1) = 2;
        const MatrixS& const_mat = mat;
        CHECK(mat.at(0, 1) == 2);
        CHECK(const_mat.at(0, 1) == 2);
    }
}