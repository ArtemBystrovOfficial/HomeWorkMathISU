#include "../headers/Macloren.hpp"
#include <cmath>

# define M_PI           3.14159265358979323846

namespace ml {
int factorial(int n) {
    int k=1;
    for(int i=1; i<=n;i++) {
        k*=i;
    }
    return k;
}

double exp(double n) {
    double sum = 0;
    for(int i=0;i<=n;i++)
        sum+= ((pow(n,i))/double(factorial(i)));
    return sum;
}

double sin(double n) {
    double sum = 0;
    for(int i=0;i<=n;i++) {
        sum+= (pow(-1, i)*(pow(n,  (2*i + 1))))/ factorial(2*i+1);
    } 
    return sum;
}

double cos(double n) {
    double sum = 0;
    for(int i=0;i<=n;i++) {
        sum+= (pow(-1, i)*(pow(n,  (2*i))))/ factorial(2*i);
    } 
    return sum;
}

double arcsin(double n) {
    double sum = 0;
    for(int i=0;i<=n;i++) {
        sum+= factorial(2*i) / ( (pow(4,i) * (pow(factorial(i),2)) * (2*i + 1)));
    } 
    return sum;
}

double arccos(double n) {
    return M_PI/2 - arcsin(n);
}

}
