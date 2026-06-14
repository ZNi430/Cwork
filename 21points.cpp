#include <stdio.h>
#include <string.h>

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    
    while (t--) {
        char a[100]; // 开稍微大一点防止溢出，虽然题目说10
        scanf("%s", a);
        int len = strlen(a);
        
        int base_sum = 0; // 非A牌的总和
        int cntA = 0;     // A的数量

        // 1. 预处理：算非A的分数，统计A的个数
        for (int i = 0; i < len; i++) {
            if (a[i] == 'A') {
                cntA++;
            } else if (a[i] == 'J' || a[i] == 'Q' || a[i] == 'K' || a[i] == '0') {
                base_sum += 10;
            } else if (a[i] == '1') { // 遇到1，说明是10
                base_sum += 10;
                i++; // 跳过后面的'0'
            } else {
                base_sum += a[i] - '0';
            }
        }

        int max_point = -1; // 记录合法的最大点数

        // 2. 暴力枚举所有 A 的可能性
        // i 代表当作 11 的 A 的数量 (只能是 0 或 1)
        for (int i = 0; i <= 1; i++) {
            // j 代表当作 10 的 A 的数量 (从 0 到 剩下所有的A)
            for (int j = 0; j <= cntA - i; j++) {
                // k 代表当作 1 的 A 的数量 (剩下的就是1)
                int k = cntA - i - j;
                
                // 只有当 A 的数量够分时才计算
                if (k >= 0) {
                    int current_sum = base_sum + (11 * i) + (10 * j) + (1 * k);
                    if (current_sum <= 21) {
                        if (current_sum > max_point) {
                            max_point = current_sum;
                        }
                    }
                }
            }
        }

        if (max_point != -1) printf("%d\n", max_point);
        else printf("Boom\n");
    }
    return 0;
}
