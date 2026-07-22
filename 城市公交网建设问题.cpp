#include <stdio.h>
#define INF 0x3f3f3f3f // 定义一个足够大的数表示不连通

int g[105][105];   // 邻接矩阵，存城市间的道路造价
int dist[105];     // 记录未连通城市到当前公交网的最短距离
int vis[105];      // 记录城市是否已经加入了公交网

int main() {
    int n, e;
    if (scanf("%d %d", &n, &e) != 2) return 0;

    // 1. 初始化图，默认所有城市间都不连通
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            g[i][j] = (i == j) ? 0 : INF;
        }
    }

    // 2. 读入边（自动处理可能存在的重边，只保留造价低的）
    for (int k = 0; k < e; k++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        if (w < g[u][v]) g[u][v] = g[v][u] = w;
    }

    // 3. 初始化：先将 1 号城市放入网络
    for (int i = 1; i <= n; i++) dist[i] = g[1][i];
    vis[1] = 1;
    int total_cost = 0;

    // 4. Prim 核心：每次加入一个点，一共需要加 n-1 个点
    for (int i = 1; i < n; i++) {
        int min_d = INF, u = -1;
        // 找出距离当前网络最近的未连通城市
        for (int j = 1; j <= n; j++) {
            if (!vis[j] && dist[j] < min_d) {
                min_d = dist[j];
                u = j;
            }
        }

        vis[u] = 1;         // 将该城市标记为已连通
        total_cost += min_d; // 累加造价

        // 更新其他未连通城市到当前网络的距离
        for (int j = 1; j <= n; j++) {
            if (!vis[j] && g[u][j] < dist[j]) {
                dist[j] = g[u][j];
            }
        }
    }

    printf("%d\n", total_cost);
    return 0;
}
