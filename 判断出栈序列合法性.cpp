
#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    int a[7];
    while (n--) {
        for (int i = 0; i < 7; i++)
            scanf("%d", &a[i]);
        int stack[7];
        int top = -1;          // 栈顶指针，-1 表示空栈
        int idx = 0;           // 待匹配序列的索引
        int next = 1;          // 下一个要入栈的数字（1 ~ 7）
        while (idx < 7) {
            // 如果栈顶不等于当前需要的数字，就压入下一个数字
            if (top == -1 || stack[top] != a[idx]) {
                if (next > 7) break;      // 所有数字都已入栈仍不匹配，非法
                stack[++top] = next++;
            } else {
                // 栈顶匹配，出栈
                top--;
                idx++;
            }
        }
        if (top == -1 && idx == 7)
            printf("Y");
        else
            printf("N");
    }
    return 0;
}
