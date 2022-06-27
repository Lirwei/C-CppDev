#include <stdio.h>

void dis_binary(char ch) {
    int i = 8;
    while (i--) {
        if ((1 << i) & ch) {
            printf("1");
        } else {
            printf("0");
        }
        if (i % 4 == 0) {
            printf(" ");
        }
    }
    putchar(10);
}

int main() {
//    char a = 0;
//    dis_binary(a);
//    char b = 1;
//    dis_binary(b);
//    char c = 2;
//    dis_binary(c);
//    char d = 127;
//    dis_binary(d);
//    char e = -128;
//    dis_binary(e);
//    char f = -2;
//    dis_binary(f);
//    char g = -1;
//    dis_binary(g);

    for (char ch = -128; ch < 127; ch++) {
        printf("%d --> ", ch);
        dis_binary(ch);
    }
    return 0;
}

/*
-1
|-1|
0000 0001
1111 1110   取反
1111 1111   加1
*/
