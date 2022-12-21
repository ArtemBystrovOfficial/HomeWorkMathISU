#include "../headers/ReverseMatrix.hpp"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

// test reserve matrix
TEST(getReverseMatrix,result1)
{
    //A

            matrix mat = {{1,2},
                          {3,4}};

    //A
            auto out = getReverseMatrix(mat);

            bool is = out == matrix{{-2.0,1.0},
                                    {1.5,-0.5}};
    //A
    ASSERT_TRUE(is);
}

//test SLAY with reserve matrix
TEST(getReverseMatrix,result2)
{
    //A

            matrix mat = {{1,2},
                          {3,4}};

    //A
            auto out1 = getReverseMatrix(mat);

            auto out2 = multiply_matrix(out1,matrix{{6},
                                       {8}});

            bool is = out2 == matrix{{-4},
                                     { 5}};


    //A
    ASSERT_TRUE(is);
}


int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}