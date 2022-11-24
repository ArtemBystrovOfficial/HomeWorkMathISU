#include "../headers/Interpolation.hpp"

#include "../headers/Gauss.hpp"

namespace {
    double y_line(double x,double kof, double a) {
        return x*kof + a;
    }
}


namespace interpolation {

matrix get_range(const matrix & mat) {
    if(mat[0].size()!=2 || mat.size()<2)
        return {};

    matrix out;
    for(int i=0;i<mat.size()-1;i++) {
        matrix mat_a(2,std::vector<double>(2));
        matrix mat_b(2,std::vector<double>(1)); 

        mat_a[0][0] = mat[i][0];
        mat_a[1][0] = mat[i+1][0];
        mat_a[0][1] = 1;
        mat_a[1][1] = 1;

        mat_b[0][0] = mat[i][1];
        mat_b[1][0] = mat[i+1][1];

        auto mat_out = MethodGauss(mat_a, mat_b);
            out.push_back({mat_out[0][0],mat_out[1][0]});
    }
    return out;
}

double get_y(double x,const std::vector<double> ranges, const matrix & kof) {

    if(ranges.empty()) {
        return 0;
    }

    if(ranges.size()==1) {
        return 0;
    }

    if(ranges.size()==2) {
        return y_line(x,kof[0][0],kof[0][1]);
    }

    if(x<=ranges[1])
        return y_line(x,kof[0][0],kof[0][1]);

    if(x>=ranges[ranges.size()-2]) {
        return y_line(x,kof[kof.size()-1][0],kof[kof.size()-1][1]);
    }

    for(int i=1;i<ranges.size()-1;i++) {
        if(ranges[i]>=x && ranges[i+1]<=x) {
            return y_line(x,kof[i][0],kof[i][1]);
        }
    }
}

}