#include <stdio.h>

// 相同的数据类型进行构造，就成了数组
// 不同的数据类型进行构造，就成了结构体

// 研究数组
// 定义/声明、大小、初始化/赋值、访问

/**
未初始化		  int arr[10]
满初始化		  int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0}
部分初始化	  int arr[10] = {1}   其余部分清零；初始化清零
越界初始化	  int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 11, 12}
不指定大小初始化 int arr[] = {1, 2, 3, 4, 5, 6}

凡事基本数据类型，既可以在定义时初始化，也可以先定义再赋值
	int a = 10;
	int b; b = 10;
	
凡事构造类型，可以在定义时初始化，不可以先定义再以初始化的方式赋值，
	如错误 int arr[10]; arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
*/
int main(int argc, char *argv[]) {

//	int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 11, 12};
    int arr[] = {1, 2, 3, 4, 5, 6};

    for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    return 0;
}