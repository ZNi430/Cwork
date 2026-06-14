#include <stdio.h>
#include <string.h> // for memset

#define N_MAX 7
#define M_MAX 501

long long max(long long a, long long b) {
    return (a > b) ? a : b;
}

// 节点信息
long long pos[N_MAX], a[N_MAX], p[N_MAX];
// dp[i][e]: 到达 节点i, 拥有 e 能量 的最大金币 (交互前)
long long dp[N_MAX][M_MAX];
// dpa[i][e]: 在 节点i 交互后, 拥有 e 能量 的最大金币 (准备出发)
long long dpa[N_MAX][M_MAX];

// 交互的临时数组
long long temp_interact[M_MAX];

int main() {
    int n;
    long long m, E, L, p0;
    
    scanf("%d", &n);
    scanf("%lld %lld %lld %lld", &m, &E, &L, &p0);

    pos[0] = 0; a[0] = 0; p[0] = p0; 
    pos[n + 1] = E; 
    
    for (int i = 1; i <= n; i++) {
        scanf("%lld %lld %lld", &pos[i], &a[i], &p[i]);
    }

    long long NEGINF = -1e18; 
    long long INF_COST = 1e18; 

    // --- 关键：每次运行 main 时都必须初始化 ---
    for (int i = 0; i < N_MAX; i++) {
        for (int j = 0; j < M_MAX; j++) {
            dp[i][j] = NEGINF;
            dpa[i][j] = NEGINF;
        }
    }

    // --- 1. 初始化起点 (Node 0) 状态 ---
    dp[0][0] = 0; 
    
    dpa[0][0] = dp[0][0]; 
    for (int e = 0; e < m; e++) {
        if (dpa[0][e] != NEGINF) {
            dpa[0][e + 1] = max(dpa[0][e + 1], dpa[0][e] - p[0]);
        }
    }
    
    // --- 2. DP 主循环 ---
    for (int i = 0; i <= n; i++) {
        
        // A) 计算 i 的出发状态 dpa[i] (如果 i > 0)
        if (i > 0) {
            
            // --- v6 修正：在循环内重置 temp_interact ---
            for (int e = 0; e <= m; e++) {
                temp_interact[e] = NEGINF; // 先全部重置为 NEGINF
            }
            
            // 1. 拿金币
            for (int e = 0; e <= m; e++) {
                if (dp[i][e] != NEGINF) { // 只有可达的状态才需要+a[i]
                    temp_interact[e] = dp[i][e] + a[i];
                }
            }
            
            // 2. 买能量 (在 temp 上)
            for (int e = 0; e < m; e++) {
                if (temp_interact[e] != NEGINF) {
                    temp_interact[e + 1] = max(temp_interact[e + 1], temp_interact[e] - p[i]);
                }
            }
            
            // 3. 存入 dpa[i]
            for (int e = 0; e <= m; e++) {
                dpa[i][e] = temp_interact[e];
            }
        }
        
        // B) 从 dpa[i] (i的出发状态) 传播到所有 j > i
        for (int e_start = 0; e_start <= m; e_start++) {
            long long gold_start = dpa[i][e_start];
            if (gold_start == NEGINF) continue;

            for (int j = i + 1; j <= n + 1; j++) {
                long long distance = pos[j] - pos[i];
                long long energy_cost;

                if (L == 0) {
                    energy_cost = (distance == 0) ? 0 : INF_COST;
                } else {
                    energy_cost = (distance + L - 1) / L;
                }

                if (e_start >= energy_cost) {
                    // e_end 保证 >= 0
                    int e_end = (int)(e_start - energy_cost);
                    // j 保证 <= n+1 (max 6), e_end 保证 <= m (max 500)
                    // 访问 dp[0..6][0..500] 绝对安全
                    dp[j][e_end] = max(dp[j][e_end], gold_start);
                }
            }
        }
    }

    // --- 3. 寻找结果 ---
    long long max_final_gold = NEGINF;
    for (int e = 0; e <= m; e++) {
        max_final_gold = max(max_final_gold, dp[n + 1][e]);
    }

    if (max_final_gold == NEGINF) {
        printf("Failure\n");
    } else {
        printf("Victory %lld\n", max_final_gold);
    }

    return 0;
}
