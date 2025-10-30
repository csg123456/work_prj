#include <stdio.h>
#include <stdlib.h>

// 函数声明
void print_call_trace(void *stack_ptr);

// 示例函数，用于演示调用轨迹
void func_c() {
    int stack_var; // 栈变量
    print_call_trace(&stack_var); // 传递栈变量的地址
}

void func_b() {
    func_c();
}

void func_a() {
    func_b();
}

int main() {
    func_a();
    // printf("func_a:%p func_b:%p func_c:%p main:%p\n", func_a, func_b, func_c, main);
    return 0;
}

// 打印函数调用轨迹
void print_call_trace(void *stack_ptr) {
    void **frame_ptr = (void **)stack_ptr; // 将栈变量地址转换为指针
    printf("Call Trace:\n");

    // 遍历调用栈
    while (frame_ptr != NULL) {
        void *return_address = *(frame_ptr + 1); // 返回地址通常位于栈帧的固定偏移处
        if (return_address == NULL) break; // 如果返回地址为空，表示到达栈底

        printf("Return Address: %p\n", return_address);
        frame_ptr = (void **)*frame_ptr; // 移动到上一个栈帧
    }
}