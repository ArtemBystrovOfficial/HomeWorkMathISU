
#include "../headers/Gauss.hpp"

#include <vector>
#include <map>

std::vector<double> MethodGauss(matrix mat,std::vector<double> con)
{

    std::map <int, bool> usebles;

    if (!mat.size())
        return std::vector<double>{};

    // only matrix n x n, other return answers with x1,x2...
    if(mat.size()!=mat[0].size())
        return std::vector<double>{};

    for(int i=0;i<mat.size();i++)
    {
        mat[i].push_back(con[i]);
    }
    
    int lvl = 0;

    while (usebles.size()!=mat.size())
    {
        for (int k = 0; k < mat.size(); k++)
        {
            if (usebles.find(k) != usebles.end() || mat[k][lvl]==0)
                continue;

            usebles[k] = true;

            multiply_row_scalar(mat, k, (1 / mat[k][lvl]));

            for (int i = 0; i < mat.size(); i++)
            {
                if (k != i)
                {
                    double kof = mat[i][lvl];
                    for (int j = lvl; j < mat[0].size(); j++)
                    {
                        mat[i][j] -= mat[k][j] * kof;
                    }
                }
            }
        }
        lvl++;
    }
    
    lvl = 0;

    while (lvl != mat.size())
    {
        for (int i = 0; i < mat.size(); i++)
        {
            if (mat[i][lvl] == 1.0)
            {
                replace_rows_matrix(mat, lvl, i);
                break;
            }
        }
        lvl++;
    }

    return get_column_matrix(mat,mat[0].size()-1);
}