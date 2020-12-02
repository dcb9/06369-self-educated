//
//  main.c
//  c6s3
//
//  Created by Bob on 2020/12/2.
//

#include <stdio.h>
#include <stdlib.h>

#define MAXN 1000

void _next(int * a, int k, int * temp) { /* 已知 a 中的 (k-1)! 求 k! */
    int i, count = a[0];
    // step1. 将 a 中的值缓存到 temp 中
    for (i = 1; i<=a[0]; i++) temp[i] = a[i];

    // step2. 将 temp 的值累加 k-1 次，存入 a 中
    int carry, sum;
    for (int n = 1; n < k; n++) {
        // 做一次带进位的加法运算
        for (carry = 0, i = 1; i<=count; i++) {
            sum = a[i] + temp[i] + carry;
            a[i] = sum % 10; carry = sum / 10;
        }
        // 如果最终有进位，则添加到高位
        if (carry) a[++count] = carry;
    }
    a[0] = count;
}

// 输出 k 的阶乘
void p(int * a, int k) {
    int i;
    printf("%4d!=", k);
    for(i = a[0]; i>0; i--) printf("%d", a[i]);
    printf("\n");
}

int main(int argc, const char * argv[]) {
    int a[MAXN], temp[MAXN], n, k;
    
    for (n = 0; n < MAXN; n++) a[n] = temp[n] = 0; // 初始化 a, temp

    printf("Enter the number n:  ");
    scanf("%d", &n);
    a[0] = a[1] = 1;
    p(a, 1);
    for (k = 2; k<=n; k++) {
        _next(a, k, temp);
        p(a, k);
//        scanf("%*c"); // 等待输入回车继续
    }

    return 0;
}
