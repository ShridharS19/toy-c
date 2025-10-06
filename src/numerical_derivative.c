#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef double (*function)(double);
#define epsilon 1E-9

double square(double d){
    return(pow(d,2));
}
double derivative(function func, double arg){
    return(func(arg + epsilon) - func(arg-epsilon))/(2*epsilon);
}

int main(void){
    printf("%.5f\n",derivative(sin, 0));
    printf("%.5f\n",derivative(cos, 0));
    printf("%.5f\n",derivative(exp, 1));
    printf("%.5f\n",derivative(square, 1));
    return EXIT_SUCCESS;
}