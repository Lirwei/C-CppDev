#include <stdio.h>

// 修正值
//#define MODIFY 0.000001
#define MODIFY (1e-6)

/*
 * 比较浮点数与0的大小
 */
int main() {
    float zero = 0.0f;
    if (zero > -MODIFY && zero < MODIFY) {
        printf("zero == 0");
    } else {
        printf("zero != 0");
    }
    return 0;
}