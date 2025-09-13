// hello.c
#include <stdio.h>

typedef struct {
    int x;
    int y;
    int *z;
} Point;

void point_init(Point *p) 
{
    printf("Point init:%p, (%p, %p), z points to %p\n", p, &p->x, &p->y, &p->z);

    printf("Before init: x=%d, y=%d, *z=%d\n", p->x, (*p).y, *(p->z));

    p->x = 100;
    p->y = 200; 
}
int main() {
    printf("Hello, World!\n");

    int a = 10; // 局部变量，存放在栈区
    *(&a) = 10;

    Point p = {1, 2, &a}; // 结构体变量，存放在栈区
    printf("Point init:%p (%p, %p), z points to %p\n",&p, &p.x, &p.y, &p.z);

    point_init(&p);
    (&p)->x = 300; 
    
    printf("after init: x=%d, y=%d, *z=%d\n", p.x, p.y, *(p.z));
    return 0;
}