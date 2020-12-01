//
//  main.c
//  c6s2
//
//  Created by Bob on 2020/12/1.
//

#include <stdio.h>

#define SIDE_N     3
#define LENGTH     3
#define VARIABLES  6

int A, B, C, D, E, F;
int * pt[] = {&A, &B, &C, &D, &E, &F};
int * side[SIDE_N][LENGTH] = {
    {&A, &B, &C},
    {&C, &D, &E},
    {&E, &F, &A}
};

// 每条边的和
int side_total[SIDE_N];

int main(int argc, const char * argv[]) {
    int i, j, t, equal;

    // 置初始排列 1,2,3,4,5,6
    for (j=0; j<VARIABLES; j++) * pt[j] = j+1;
    
    // 循环穷举所有排列
    while(1) {
//        printf("当前组合：%d %d %d %d %d %d\n", A, B, C, D, E, F);
        for (i = 0; i<SIDE_N; i++) { /* 求各边之和 */
            for (t = j =0; j<LENGTH; j++) t += *side[i][j];
            side_total[i] = t;
        }
        // 判断三边之和是否相等，若相等，则打印
        for (equal=1, i=0; equal && i<SIDE_N-1; i++)
            if (side_total[i] != side_total[i+1]) equal = 0;
        if (equal) {
            for(i=0; i<VARIABLES; i++) {
                printf("%3d", *pt[i]);
            }
            printf("\n");
            // scanf("%*c"); /* 等待输入回车，找下一个解*/
        }
        
        // 从当前排列找出下一个排列
        for (i = VARIABLES -1; i>0; i--) {
            if (*pt[i-1] < *pt[i]) {
                // 找到了需要交换的
                break;
            }
        }
        
        if (i==0) {
            printf("没有更多的排列了，终止 while 循环\n");
            break; // 已经没有更大的排列，终止 while 循环
        }
        // 寻找交换元素
        for (j = VARIABLES -1; j>i; j--)
            if (*pt[j] > *pt[i-1]) break;
        // 交换元素
        t = *pt[j]; *pt[j] = *pt[i-1]; *pt[i-1] = t;
        
        // 后部分元素倒置
        for(j = VARIABLES -1; j > i; j--, i++) {
            t = *pt[i];
            *pt[i] = *pt[j];
            *pt[j] = t;
        }
    }
    return 0;
}
