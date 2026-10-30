#include <math.h>
#include <stdio.h>

double Integral(double(*func)(double), double from, double to, double step)
{
    double sum = 0.0;

    int n = (to - from) / step;
    if (n < 0)
        n *= -1;

    if (from > to)
        step = -step;

    for (int i = 0; i < n; ++i)
        sum += (func(from + step * i) + func(from + step * (i+1))) / 2 * step;

    return sum;
}

int main() 
{
    double res;

    res = Integral(sin, 0, 3.14159/5, 0.0001);
    printf("Result: %lf\n", res);
    return 0;
}