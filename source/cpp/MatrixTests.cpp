
#include "../headers/Matrix.hpp"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

bool operator==(const matrix& mat1, const matrix& mat2)
{
    if (mat1.size() != mat2.size())
        return false;

    if (!mat1.size())
        return true;

    for (int i = 0; i < mat1.size(); i++)
        if (mat1[i].size() != mat2[i].size())
            return false;

    for (int i = 0; i < mat1.size(); i++)
    {
        for (int j = 0; j < mat1[i].size(); j++)
        {
            if (mat1[i][j] != mat2[i][j])
                return false;
        }
    }
    return true;
}

bool operator==(const std::vector<int> & vec1,const std::vector<int> & vec2)
{
    if (vec1.size() != vec2.size())
        return false;
    for (int i = 0; i < vec1.size(); i++)
    {
        if (vec1[i] != vec2[i])
            return false;
    }
    return true;
}

TEST(sum_matrix, test_result)
{

    //A
    
    //A
    auto opt = sum_matrix({ {1,2,3},
                            {4,5,6},
                            {7,8,9} },

                          { {2,3,4},
                            {5,6,7},
                            {8,9,0} });

bool is1 = opt.has_value();
bool is2 = opt.value() == matrix{ {3, 5, 7 },
                                  {9, 11,13},
                                  {15,17,9 } };

    //A

    ASSERT_EQ(is1, true);
    ASSERT_EQ(is2, true);

}

TEST(sum_matrix, test_fail1)
{

    //A
    
    //A
    auto opt = sum_matrix({ {1,2,3},
                            {4,5,6},
                            {7,8,9} },

                          { {2,3,4},
                            {5,6,7},
                            {8,9,0} });

bool is1 = opt.has_value();
bool is2 = opt.value() == matrix{ {3, 3, 7 },
                                  {9, 4, 13},
                                  {15,67,9 } };

    //A

    ASSERT_EQ(is1, true);
    ASSERT_EQ(is2, false);

}

TEST(sum_matrix, test_fail2)
{

    //A

    //A
    auto opt = sum_matrix({ {1,2,3},
                            {4,5,6},
                            {7,8,9} },

                          { {2,3},
                            {5,6,7},
                            {9,0} });

    bool is1 = opt.has_value();

    //A

    ASSERT_EQ(is1, false);

}

TEST(substration_matrix, test_result)
{
    //A

    //A
    auto opt = subtraction_matrix( { {1,2,3},
                                     {4,5,6},
                                     {7,8,9} },

                                   { {2,3,4},
                                     {5,6,7},
                                     {8,9,0} });

    bool is1 = opt.has_value();
    bool is2 = opt.value() == matrix{ {-1, -1, -1 },
                                      {-1, -1, -1},
                                      {-1, -1, 9 } };

    //A

    ASSERT_EQ( is1, true );
    ASSERT_EQ( is2, true );
}

TEST(transport_matrix, test_result)
{
    //A

    auto mat = matrix({ {1,2},
                        {4,5},
                        {7,8} });

    //A

    transport_matrix(mat);

    bool is = mat == matrix{ { 1, 4, 7 },
                             { 2, 5, 8 } };

    //A

    ASSERT_EQ(is, true);

}

TEST(multiply_matrix_scalar, test_result)
{
    //A

    auto mat = matrix{ { 1, 4, 7 },
                       { 2, 5, 8 } };

    //A

    multiply_matrix_scalar(mat, 2);

    bool is = mat == matrix{ { 2, 8, 14 },
                             { 4, 10, 16 } };

    //A

    ASSERT_EQ(is, true);

}

TEST(multiply_matrix, test_result)
{
    //A

    auto mat1 = matrix{ { 1, 4 },
                        { 7, 2 },
                        { 5, 8 } };

    auto mat2 = matrix{ { 2, 4},
                        { 5, 6} };

    //A

    auto mat = multiply_matrix(mat1, mat2);

    bool is1 = mat.has_value();
    bool is2 = mat == matrix{ { 22, 28 },
                              { 24, 40 },
                              { 50, 68 } };

    //A

    ASSERT_EQ(is1, true);
    ASSERT_EQ(is2, true);

}

TEST(get_row_matrix, test_result)
{
    //A

    auto mat = matrix{ { 1, 4 },
                        { 7, 2 },
                        { 5, 8 } };

    //A

    auto & row = get_row_matrix(mat, 1);

    bool is = row == std::vector<int>{ 7, 2 };

    //A

    ASSERT_EQ(is, true);

}

TEST(get_column_matrix, test_result)
{
    //A

    auto mat = matrix{ { 1, 4 },
                        { 7, 2 },
                        { 5, 8 } };

    //A

    auto& row = get_column_matrix(mat, 0);

    bool is = row == std::vector<int>{ 1, 7, 5 };

    //A

    ASSERT_EQ(is, true);

}

TEST(replace_rows_matrix, test_result)
{
    //A

    auto mat = matrix{ { 1, 4 },
                        { 7, 2 },
                        { 5, 8 } };

    //A

    replace_rows_matrix(mat,1, 2);

    bool is = mat == matrix{ { 1, 4 },
                             { 5, 8 },
                             { 7, 2 } };

    //A

    ASSERT_EQ(is, true);

}

TEST(multiply_row_scalar, test_result)
{
    //A

    auto mat = matrix{ { 1, 4 },
                        { 7, 2 },
                        { 5, 8 } };

    //A

    multiply_row_scalar(mat, 0, 5);

    bool is = mat == matrix{ { 5, 20 },
                             { 7, 2 },
                             { 5, 8 } };

    //A

    ASSERT_EQ(is, true);

}

TEST(sum_rows_scalar, test_result)
{
    //A

    auto mat1 = matrix{ { 1, 4 },
                        { 7, 2 },
                        { 5, 8 } };

    auto mat2 = matrix{ { 2, 2 },
                        { 4, 3 },
                        { 5, 2 } };

    //A

    auto vec = sum_rows_scalar(mat1, mat2, 1, 2, 4);

    bool is = vec == std::vector<int>{48, 16};

    //A

    ASSERT_EQ(is, true);

}

TEST(subtraction_rows_scalar, test_result)
{
    //A

    auto mat1 = matrix{ { 1, 4 },
                        { 7, 2 },
                        { 5, 8 } };

    auto mat2 = matrix{ { 2, 2 },
                        { 4, 3 },
                        { 5, 2 } };

    //A

    auto vec = subtraction_rows_scalar(mat1, mat2, 1, 2, 4);

    bool is = vec == std::vector<int>{8, 0};

    //A

    ASSERT_EQ(is, true);

}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}