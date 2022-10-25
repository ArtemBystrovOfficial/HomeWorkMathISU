#include "../headers/Gauss.hpp"

#include <gtest/gtest.h>
#include <gmock/gmock.h>


TEST(gauss,test_result)
{
    //A

    matrix mat = {{4, -7, 8},
                  {2, -4, 5},
                  {-3, 11, 1}};

    std::vector <double> vec{-23, -13, 16};


    //A

    MethodGauss(mat,vec);

    //A
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}