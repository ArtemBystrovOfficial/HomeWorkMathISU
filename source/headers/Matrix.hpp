#pragma once

#include <iostream>
#include <vector>
#include <optional>
#include <algorithm>

//!!!standart 17

using matrix = std::vector < std::vector < double > >;

bool is_matrix(const matrix& mat);

bool is_matrix_equal_size(const matrix& mat1, const matrix& mat2) noexcept;

//1
// intilization without copying with rule of three - standart 11-14
std::optional<matrix> sum_matrix(const matrix& mat1, const matrix& mat2) noexcept;
//2
// intilization without copying with rule of three - standart 11-14
std::optional<matrix> subtraction_matrix(const matrix& mat1, const matrix& mat2) noexcept;

//3
void transport_matrix(matrix& mat) noexcept;

//4
void multiply_matrix_scalar(matrix& mat, int scalar) noexcept;

//5
std::optional<matrix> multiply_matrix(const matrix& mat1, const  matrix& mat2) noexcept;

//6
 std::vector<double> &  get_row_matrix(matrix& mat, int row) noexcept;

//7
 std::vector<double>  get_column_matrix(matrix & mat, int column) noexcept;

//8
void replace_rows_matrix(matrix& mat, int row1, int row2) noexcept;

//9
void multiply_row_scalar(matrix& mat, int row, double scalar);

//10
std::vector<double> sum_rows_scalar(const matrix& mat1, const matrix& mat2, int row1, int row2, int scalar);

std::vector<double> subtraction_rows_scalar(const matrix& mat1, const matrix& mat2, int row1, int row2, int scalar);
