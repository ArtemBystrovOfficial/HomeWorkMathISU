#include "../headers/Gauss.hpp"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

bool operator==(const std::vector<double>& vec1, const std::vector<double>& vec2)
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


TEST(gauss,test_result1)
{
    //A

    matrix mat = {{4, -7, 8},
                  {2, -4, 5},
                  {-3, 11, 1}};

    matrix mat2{{-23}, {-13}, {16}};

    //A

    auto out = MethodGauss(mat,mat2);


    bool is = out == matrix{ {-2.0}, {1.0}, {-1.0}};

    //A

    ASSERT_TRUE(is);

}

TEST(gauss, test_result2)
{
    //A

    matrix mat = {{-1, 2, 6},
                  {3, -6, 0},
                  {1, 0, 6} };

    matrix mat2{ {15}, {-9}, {5} };


    //A

    auto out = MethodGauss(mat, mat2);

    bool is = out == matrix{{-7}, {-2}, {2}};

    //A

    ASSERT_TRUE(is);

}

TEST(gauss, test_result3)
{
    //A

    matrix mat = { {2, 3},
                   {4, 3} };

    matrix mat2{ {2}, {7} };


    //A

    auto out = MethodGauss(mat, mat2);

    bool is = out == matrix{{2.5}, {-1}};

    //A

    ASSERT_TRUE(is);

}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}