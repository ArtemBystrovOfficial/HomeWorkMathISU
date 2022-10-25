#include "../headers/Matrix.hpp"


bool is_matrix(const matrix& mat)
{
    if (!mat.size())
        return false;


    auto out = std::count_if(mat.begin(), mat.end(), [=](const std::vector<double> & vec) {
        
        return vec.size() == mat[0].size();

        });

    return out == mat.size();
}

bool is_matrix_equal_size(const matrix& mat1, const matrix& mat2) noexcept
{

    if (!is_matrix(mat1) || !is_matrix(mat2))
        return false;

    if (mat1.size() == 0)
        return false;

    if (mat1.size() != mat2.size())
        return false;
    for (int i = 0; i < mat1.size(); i++)
    {
        if (mat1[i].size() != mat2[i].size())
            return false;
    }
    return true;
}

//1
// intilization without copying with rule of three - standart 11-14
std::optional<matrix> sum_matrix(const matrix& mat1, const matrix& mat2) noexcept
{

    if (!is_matrix_equal_size(mat1, mat2))
        return std::nullopt;

    matrix out(mat1.size(), std::vector<double>(mat1[0].size()));

    for (int i = 0; i < mat1.size(); i++)
    {
        for (int j = 0; j < mat1[i].size(); j++)
        {
            out[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    return out;
}

//2
// intilization without copying with rule of three - standart 11-14
std::optional<matrix> subtraction_matrix(const matrix& mat1, const matrix& mat2) noexcept
{

    if (!is_matrix_equal_size(mat1, mat2))
        return std::nullopt;

    matrix out(mat1.size(), std::vector<double>(mat1[0].size()));

    for (int i = 0; i < mat1.size(); i++)
    {
        for (int j = 0; j < mat1[i].size(); j++)
        {
            out[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
    return out;
}

//3
void transport_matrix(matrix& mat) noexcept
{

    if (!is_matrix(mat))
        return;

    if (!mat.size())
        return;

    matrix data(mat[0].size(), std::vector<double>(mat.size()));

    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[0].size(); j++)
        {
            data[j][i] = mat[i][j];
        }
    }
    mat = data;
}

//4
void multiply_matrix_scalar(matrix& mat, int scalar) noexcept
{
    // without exceptions
    if (!is_matrix(mat))
        return;

    for (auto& vec : mat)
        for (auto& elem : vec)
            elem *= scalar;
}

//5
std::optional<matrix> multiply_matrix(const matrix& mat1, const  matrix& mat2) noexcept
{
    matrix mat_out(mat1.size(),std::vector<double>(mat1[0].size()));

    if (!is_matrix(mat1) || !is_matrix(mat2))
        return std::nullopt;

    if (!mat1.size() || !mat2.size())
        return std::nullopt;

    if(mat1[0].size() != mat2.size())
        return std::nullopt;

    int out;


    for (int i = 0; i < mat1.size(); i++)
    {
        for (int z = 0; z < mat1[0].size(); z++)
        {
            out = 0;
            for (int j = 0; j < mat1[0].size(); j++)
            {
                out += mat1[i][j] * mat2[j][z];
            }
            mat_out[i][z] = out;
        }
    }

    return mat_out;

}

//6
 std::vector<double> & get_row_matrix(matrix& mat, int row) noexcept
{
    try {
        return mat.at(row);
    }
    catch (std::out_of_range const& exc) {

    }

}

//7
 std::vector<double> get_column_matrix(matrix & mat, int column) noexcept
{
    transport_matrix(mat);

    // smart compiler not copy this block
    auto vec = get_row_matrix(mat, column);

    transport_matrix(mat);

    return vec;

}

//8
void replace_rows_matrix(matrix& mat, int row1, int row2) noexcept
{
    try {
        swap(mat.at(row1), mat.at(row2));
    }
    catch(std::out_of_range const& exc) {
        // exception sematic with your realization
    }
}

//9
void multiply_row_scalar(matrix& mat, int row, double scalar)
{
    auto & vec = get_row_matrix(mat, row);

    std::for_each(vec.begin(), vec.end(), [=](double & elem) {elem *= scalar; });
}

//10
std::vector<double> sum_rows_scalar(const matrix& mat1, const matrix& mat2, int row1, int row2, int scalar)
{

    //extra safe
    if (!is_matrix(mat1) || !is_matrix(mat2))
        return std::vector<double>{};

    if (!mat1.size() || !mat2.size())
        return std::vector<double>{};

    if (mat1[0].size() != mat2[0].size())
        return std::vector<double>{};

    std::vector<double> out;

    for (int i = 0; i < mat1[row1].size(); i++)
    {
        out.push_back((mat1[row1][i] + mat2[row2][i]) * scalar);
    }
    
    return out;
}

std::vector<double> subtraction_rows_scalar(const matrix& mat1, const matrix& mat2, int row1, int row2, int scalar)
{

    //extra safe
    if (!is_matrix(mat1) || !is_matrix(mat2))
        return std::vector<double>{};

    if (!mat1.size() || !mat2.size())
        return std::vector<double>{};

    if (mat1[0].size() != mat2[0].size())
        return std::vector<double>{};

    std::vector<double> out;

    for (int i = 0; i < mat1[row1].size(); i++)
    {
        out.push_back((mat1[row1][i] - mat2[row2][i]) * scalar);
    }

    return out;
}

