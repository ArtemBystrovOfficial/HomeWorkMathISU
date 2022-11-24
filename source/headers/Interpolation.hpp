#pragma once

#include "Matrix.hpp"

namespace interpolation {

matrix get_range(const matrix & matrix);
double get_y(double x,const std::vector<double> ranges, const matrix & kof); //return y

}