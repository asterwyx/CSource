#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>

double GetAbs(double x) {
    if (x >= 0) {
        return x;
    } else {
        return -x;
    }
}

double GetSin(double x) {
    double sn = x, rn = x; // 初始化
    int n = 1;
    while (GetAbs(rn) >= 0.00001) {
        rn = rn * (- (x * x) / ((2 * n + 1) * (2 * n)));
        sn += rn;
        n++;
    }
    return sn;
}

int main() {
    printf("结果为: %f\n", GetSin(M_PI / 3));
    system("pause");
    return 0;
}