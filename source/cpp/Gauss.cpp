
#include "../headers/Gauss.hpp"

#include <vector>
#include <map>
#include <iostream>

matrix MethodGauss(matrix mat,matrix con)
{

    std::map <int, bool> usebles;

    if (!mat.size())
        return matrix{};

    if (!con.size())
        return matrix{};    

    // only matrix n x n, other return answers with x1,x2...
    if(mat.size()!=mat[0].size())
        return matrix{};

    for(int j=0;j<mat.size();j++)
    {
        for(int i=0;i<con[0].size();i++)
        {
            mat[j].push_back(con[j][i]);
        }
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

    matrix out(con.size(),std::vector<double>(con[0].size()));

    for(int i=0;i<con[0].size();i++)
    {
        auto vec = get_column_matrix(mat,mat.size()+i);

        for(int j = 0 ; j < vec.size();j++)
             out[j][i] = vec[j];
    }

    return out;
}