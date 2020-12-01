//
//  c6s1.c
//  c6s1
//
//  Created by Bob on 2020/12/1.
//

#include "c6s1.h"
#include <stdio.h>
#include <math.h>

double g(double x) {
    return pow(x + 1.0, 1.0/3.0);
}

int rootfx(fpt g, double initRoot, double epsilon, double * root) {
    double x1, x0 = initRoot; // x0 为初始近似值
    // n 用于统计计数
    int n = 0;
    do {
        printf("x%d = %0.5f\n", n, x0);
        x1 = x0;
        x0 = g(x0);
        n++;
    }while (fabs(x1 - x0) > epsilon);
    * root = x0;
    return n;
}
