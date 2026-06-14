#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_N 100005  // 筛选范围，根据题目要求修改

// sum 记录素数个数
// primes[] 存放筛选出来的素数
// visited[] 用于标记是否为合数（false表示是素数，true表示是合数）
int primes[MAX_N];
bool visited[MAX_N];
int cnt = 0; 

void euler_sieve(int n) {
    // 初始化 visited 数组，默认全是 false (即假设全是素数)
    memset(visited, false, sizeof(visited));
    
    // 0 和 1 不是素数，通常算法从 2 开始
    visited[0] = visited[1] = true;

    for (int i = 2; i <= n; i++) {
        // 如果当前数字 i 没有被标记过，说明它是素数
        if (!visited[i]) {
            primes[cnt++] = i;
        }

        // 遍历当前已经找到的素数 primes[j]
        // 将 i * primes[j] 标记为合数
        for (int j = 0; j < cnt; j++) {
            // 防止越界：如果 i * primes[j] 超过了 n，就没有必要筛了
            if (i * primes[j] > n) break;

            // 标记合数
            visited[i * primes[j]] = true;

            // 【关键核心】
            // 如果 i 能被 primes[j] 整除，说明 primes[j] 是 i 的最小质因子
            // 同时也说明 primes[j] 是 (i * primes[j+1]) 的最小质因子
            // 为了保证线性时间复杂度，必须立刻跳出循环
            if (i % primes[j] == 0) {
                break; 
            }
        }
    }
}

int main() {
    int n;
    printf("请输入筛选范围 N: ");
    if (scanf("%d", &n) != 1) return 1;

    // 运行欧拉筛
    euler_sieve(n);

    printf("1 到 %d 之间的素数个数: %d\n", n, cnt);
    printf("前 10 个素数 (若有): ");
    for (int i = 0; i < cnt ; i++) {
        printf("if(x%% %d ==0)return 0;\n", primes[i]);
    }
    printf("\n");

    return 0;
}
