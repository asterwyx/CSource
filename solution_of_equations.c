#define _USE_MATH_DEFINES
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define E_12_BIT    0.000000000001
#define E_11_BIT    0.00000000001
#define E_10_BIT    0.0000000001
#define E_9_BIT     0.000000001
#define E_8_BIT     0.00000001
#define E_7_BIT     0.0000001
#define E_6_BIT     0.000001
#define E_5_BIT     0.00001
#define E_4_BIT     0.0001
#define E_3_BIT     0.001


#define L1 (M_SQRT2 / 4)
typedef double (*iter_function)(double);

double my_abs(double x);


void acc_iter(double base, iter_function f, double l, double error)
{
    printf("基础值：%.12f\n", base);
    double result = base;
    double acc_rate = 1 / (1 - l);
    int i = 1;
    do
    {
        base = result;
        result = acc_rate * (f(base) - l * base);
        printf("第%d\t次迭代结果：%.12f\n", i++, result);
    } while (my_abs(result - base) > error);
}

void jacobi_iter(double base, iter_function f, double error)
{
    printf("基础值：%.12f\n", base);
    double result = base;
    int i = 1;
    do
    {
        base = result;
        result = f(base);
        printf("第%d\t次迭代结果：%.12f\n", i++, result);
    } while (my_abs(result - base) > error);
}

void newton_iter(double base, iter_function f, iter_function df, double error)
{
    printf("基础值：%.12f\n", base);
    double result = base;
    int i = 1;
    do
    {
        base = result;
        result = base - (f(base) / df(base));
        printf("第%d\t次迭代结果：%.12f\n", i++, result);
    } while (my_abs(result - base) > error);
}

double f(double x0)
{
    return (x0 * x0 * x0 - 2 * x0 * x0 - 4 * x0 - 7);
}

double df(double x0)
{
    return (3 * x0 * x0 - 4 * x0 - 4);
}

// 主函数
int main(void)
{
    newton_iter(3, f, df, E_4_BIT);
    system("pause");
    return 0;
}

double my_abs(double x)
{
    if (x >= 0)
    {
        return x;
    }
    else
    {
        return -x;
    }
}