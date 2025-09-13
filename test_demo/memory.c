#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char a[] = "hello world"; // 全局已初始化数组，内容存放在 .data（可写）；字符串字面量实现上通常位于 .rodata
char b = 'A';             // 全局已初始化变量，存放在 .data（可写）
int  f;                   // 全局未初始化变量，存放在 .bss（启动时被清零）

int main()                // 主函数，存放在.text段
{
    char *str = "hello world";            // 指针str是局部变量，存放在栈区，字符串字面量通常位于.rodata
    int c = 0;                            // 局部变量，存放在栈区
    int *d = (int *)malloc(sizeof(int));  // 动态分配的内存,存放在堆区,d是局部变量,d的地址存放在栈区,d的值是堆区地址
    if (d == NULL) {
        printf("malloc failed!\n");
        return -1;
    }
    *d = 0x11223344;                      // 给动态分配的内存赋值

    printf("&main = %p, str = %p, &a = %p, &b = %p, &f = %p, d = %p, &str = %p, &c = %p, &d = %p. \n", 
           &main, str, &a, &b, &f, d, &str, &c, &d);

    return 0;
}

// 通过查看输出的地址，可以分析各个变量所在的内存区域
// 也可以通过查看编译生成的可执行文件的段布局来验证
// gcc -o test test.c
// readelf -S test
// objdump -h test
// &main = 00401460, str = 00405064, &a = 00404004, &b = 00404010, &f = 00407070, d = 00C41678, &str = 0061FF1C, &c = 0061FF18, &d = 0061FF14.
