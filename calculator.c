#include "calculator.h"
#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    if (b == 0) {
        printf("除数不能为0！\n");
        return 0;
    }
    return a / b;
}

int main() {
    int a, b, choice, result;
    printf("请输入两个整数：");
    scanf("%d %d", &a, &b);
    printf("请选择运算类型：1.加法 2.减法 3.乘法 4.除法\n");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            result = add(a, b);
            printf("结果：%d\n", result);
            break;
        case 2:
            result = subtract(a, b);
            printf("结果：%d\n", result);
            break;
        case 3:
            result = multiply(a, b);
            printf("结果：%d\n", result);
            break;
        case 4:
            result = divide(a, b);
            printf("结果：%d\n", result);
            break;
        default:
            printf("无效选择！\n");
    }
    return 0;
}
