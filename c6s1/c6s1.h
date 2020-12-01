//
//  c6s1.h
//  c6s1
//
//  Created by Bob on 2020/12/1.
//

#ifndef c6s1_h
#define c6s1_h

// 定义函数指针
typedef double (*fpt)(double);

// 定义求解的函数签名
int rootfx(fpt g , double initRoot, double epsilon, double * root);

// 定义g函数的函数签名
double g(double);

#endif /* c6s1_h */
