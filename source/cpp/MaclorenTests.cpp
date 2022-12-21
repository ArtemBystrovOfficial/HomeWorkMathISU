#include "../headers/Macloren.hpp"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

TEST(ml,factorial) {
    ASSERT_EQ(ml::factorial(6),720);
}

TEST(ml,exp1) {
    ASSERT_EQ(ml::exp(0),1);
    ASSERT_EQ(ml::exp(1),2);
    ASSERT_EQ(ml::exp(2),5);        
}

TEST(ml,sin1) {
    ASSERT_EQ(ml::sin(0),0);
    ASSERT_EQ(ml::sin(1),0.8333333333333334);
    ASSERT_EQ(ml::sin(2),0.9333333333333333);        
}

TEST(ml,cos1) {
    ASSERT_EQ(ml::cos(0),1);
    ASSERT_EQ(ml::cos(1),0.5);
    ASSERT_EQ(ml::cos(2),-0.33333333333333337);      
}

TEST(ml,arcsin) {
    ASSERT_EQ(ml::arcsin(0),1);
    ASSERT_EQ(ml::arcsin(1),1.1666666666666667);
    ASSERT_EQ(ml::arcsin(2),1.2416666666666667);  
}

TEST(ml,arccos) {
    ASSERT_EQ(ml::arccos(0),0.5707963267948966);
    ASSERT_EQ(ml::arccos(1),0.4041296601282298);
    ASSERT_EQ(ml::arccos(2),0.32912966012822986);  
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}