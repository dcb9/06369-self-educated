//
//  main.c
//  c6s1: chapter 6 section 1
//  求 x = (x+1)^(1/3) 的近似解
//  该方程可写为 x = g(x)
//  Created by Bob on 2020/12/1.
//

#include <stdio.h>
#include "c6s1.h"

int main(void) {
    double x;
    int n = rootfx(g, 1.5, 0.000005, &x);
    printf("迭代%d次，根为%0.5f\n", n, x);
    return 0;
}
