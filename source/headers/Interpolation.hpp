#pragma once

#include "Matrix.hpp"

namespace  lagrange {

    double get_kof(const std::vector<double> & xes, double i, double x);
    double get_y(double x,matrix & mat);
    
}

namespace interpolation {

matrix get_range(const matrix & matrix);
double get_y(double x,const std::vector<double> ranges, const matrix & kof); //return y

}