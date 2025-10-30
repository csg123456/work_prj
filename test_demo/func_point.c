#include <stdio.h>


typedef struct {
    int a;
    int b;
    int c;
} st_test;

int* func_0(void)
{
    int a[] = {1, 2, 3};
    return a;
}

void func_1(st_test *test)
{
    test->a = 10;
    test->b = 20;
    test->c = 30;
}

void test_2(void)
{
    st_test test;
    func_1(&test);
    printf("%d %d %d\n", test.a, test.b, test.c);
}

void test_1(void)
{
    int *p_test = func_0();
    printf("%d %d %d\n", p_test[0], p_test[1], p_test[2]);
    test_2();
    printf("%d %d %d\n", p_test[0], p_test[1], p_test[2]);
}

int main() 
{
    test_1();
    test_2();
    return 0;
}