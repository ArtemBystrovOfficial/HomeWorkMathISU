#include "../headers/Interpolation.hpp"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

TEST(interpolation,test1) {
    //A
        matrix mat = { {1,2}, {3,4} ,{3.5,3}, {6,7}};
        std::vector<double> xes = {-1.5,3,2,5,9};
        std::vector<double> test = {-0.5,4,3,5.4,11.8};
    //A
        auto kofes = interpolation::get_range(mat);
        std::vector<double> out;
        for(auto & x : xes) {
            out.push_back(interpolation::get_y(x,get_column_matrix(mat,0),kofes));
        }

    //A
    for(int i=0;i<out.size();i++) {
        ASSERT_EQ(std::to_string(out[i]),std::to_string(test[i]));
    }
}

TEST(lagrange,test1) {

}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

