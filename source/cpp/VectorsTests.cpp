
#include "../headers/Vectors.hpp"

#include <gtest/gtest.h>
#include <gmock/gmock.h>



TEST(plus, test_result)
{
    //A
        Vec a = {1,2} , b = {2,4};
    //A
        auto out = a + b;
    
        bool is = out == Vec{ 3,6 };
    //A
        ASSERT_TRUE(is);
}

TEST(minus, test_result)
{
    //A
    Vec a = { 1,2 }, b = { 2,4 };
    //A
    auto out = a - b;

    bool is = out == Vec{ -1,-2 };
    //A
    ASSERT_TRUE(is);
}

TEST(multiply, test_result)
{
    //A
    Vec a = { 1,2 }, b = { 2,4 };
    //A
    auto out = a * b;

    bool is = out == Vec{ 2,8 };
    //A
    ASSERT_TRUE(is);
}

TEST(div, test_result)
{
    //A
    Vec a = { 1,2 }, b = { 2,4 };
    //A
    auto out = a / b;

    bool is = out == Vec{ 0.5 ,0.5 };
    //A
    ASSERT_TRUE(is);
}

TEST(eq, test_result)
{
    //A
    Vec a = { 1,2 }, b = { 2,4 };
    //A
    auto out = eq(a, b);
    //A
    ASSERT_TRUE(out);
}

TEST(isEqualOrientation, test_result)
{
    //A
    Vec a = { 1,2 }, b = { 2,4 };
    //A
    auto out = isEqualOrientation(a, b);
    //A
    ASSERT_TRUE(out);
}


int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}
