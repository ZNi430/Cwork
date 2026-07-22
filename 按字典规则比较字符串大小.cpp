#include <stdio.h>
#include <string.h>

int main() {
    char a[1005], b[1005];

    fgets(a, 1005, stdin);
    fgets(b, 1005, stdin);

    // 去掉换行（最简单写法）
    a[strlen(a) - 1] = 0;
    b[strlen(b) - 1] = 0;

    int i = 0;

    while (a[i] && b[i]) {

        char x = a[i];
        char y = b[i];

        // 空格最小
        if (x == ' ' && y != ' ') {
            printf("-1\n");
            return 0;
        }
        if (x != ' ' && y == ' ') {
            printf("1\n");
            return 0;
        }

        // 统一成小写比较
        if (x >= 'A' && x <= 'Z') x += 32;
        if (y >= 'A' && y <= 'Z') y += 32;

        if (x != y) {
            if (x > y) printf("1\n");
            else printf("-1\n");
            return 0;
        }

        // 如果字母一样，但原字符不同（大小写问题）
        if (a[i] != b[i]) {
            if (a[i] > b[i]) printf("1\n");
            else printf("-1\n");
            return 0;
        }

        i++;
    }

    // 谁长谁大
    if (strlen(a) > strlen(b)) printf("1\n");
    else if (strlen(a) < strlen(b)) printf("-1\n");
    else printf("0\n");

    return 0;
}
