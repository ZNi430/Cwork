#include <stdio;

int g[505][505];     // 邻接矩阵，存两个点之间的栅栏数量
int deg[505];        // 记录每个点的度数（连接的栅栏数）
int path[1050];      // 记录走过的路径
int path_cnt = 0;    // 路径中的节点计数

// 核心：深度优先搜索（Hierholzer 算法）
void dfs(int u) {
    // 从 1 到 500 从小到大遍历邻居，天然保证了字典序最小
    for (int v = 1; v <= 500; v++) {
        if (g[u][v] > 0) {
            g[u][v]--;   // 删掉这条栅栏（因为无向图，两边都要减）
            g[v][u]--;
            dfs(v);      // 顺着走下去
        }
    }
    // 没路可走时，说明这个点是当前走完的“圈”的终点，记录到路径中
    path[path_cnt++] = u;
}

int main() {
    int f;
    if (scanf("%d", &f) != 1) return 0;

    // 1. 读入数据，建图
    for (int i = 0; i < f; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u][v]++;
        g[v][u]++;
        deg[u]++;
        deg[v]++;
    }

    // 2. 寻找起点
    int start = -1;
    // 优先找编号最小的“奇数度”节点
    for (int i = 1; i <= 500; i++) {
        if (deg[i] % 2 != 0) {
            start = i;
            break;
        }
    }
    // 如果没有奇数度节点（即欧拉回路），就找编号最小的、有栅栏连接的节点
    if (start == -1) {
        for (int i = 1; i <= 500; i++) {
            if (deg[i] > 0) {
                start = i;
                break;
            }
        }
    }

    // 3. 开始一笔画搜索
    dfs(start);

    // 4. 逆序输出结果（因为先走完的被先压入 path 数组）
    for (int i = path_cnt - 1; i >= 0; i--) {
        printf("%d\n", path[i]);
    }

    return 0;
}
