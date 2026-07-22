#include <stdio.h>

int main() {
    char s[100], res[100];
    int from, to, len = 0;
    long long num = 0;

    printf("请输入：[数值] [原进制] [目标进制] (例如: 1010 2 10)\n");
    if (scanf("%s %d %d", s, &from, &to) != 3) return 0;

    // 步骤 1：任意进制转成 10 进制
    for (int i = 0; s[i] != '\0'; i++) {
        // 兼容处理大小写字母和数字
        int d = (s[i] >= 'a') ? (s[i] - 'a' + 10) :
                (s[i] >= 'A') ? (s[i] - 'A' + 10) : (s[i] - '0');
        num = num * from + d;
    }

    // 步骤 2：10 进制转成目标进制（余数暂存到 res 数组中）
    if (num == 0) res[len++] = '0';
    while (num > 0) {
        res[len++] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[num % to];
        num /= to;
    }

    // 步骤 3：反向打印 res 数组，即为最终结果
    while (len > 0) {
        putchar(res[--len]);
    }
    putchar('\n');

    return 0;
}
