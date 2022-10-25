
#include "../headers/Gauss.hpp"

#include <vector>

std::vector<double> MethodGauss(matrix mat,std::vector<double> con)
{

    for(int i=0;i<mat.size();i++)
    {
        mat[i].push_back(con[i]);
    }

    for(int k=0;k < mat.size();k++)
    {

        multiply_row_scalar(mat,k,(1/mat[k][k]));   

        for(int i=0;i<mat.size();i++)
        {
            if(k!=i)
            {
                double kof = mat[i][k];
                for(int j=k;j<mat[0].size();j++)
                {
                    mat[i][j]-=mat[k][j]*kof;
                }
            }
        }
    }
    return get_column_matrix(mat,mat[0].size());
}