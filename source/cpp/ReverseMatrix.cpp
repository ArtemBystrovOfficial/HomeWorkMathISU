
#include "../headers/ReverseMatrix.hpp"

matrix getReverseMatrix(matrix mat)
{
    if(mat.size()!=mat[0].size())
        return matrix{};

    matrix ed(mat.size(),std::vector<double>(mat.size()));

    for(int i=0;i<mat.size();i++)
        for(int j=0;j<mat.size();j++)
            if(i==j)
              ed[i][j]= 1;
            else
              ed[i][j] = 0;

    auto out = MethodGauss(mat,ed);
    return out;
}