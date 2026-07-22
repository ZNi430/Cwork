
#include <stdio.h>

int tree[1005]; // 存储完全二叉树的节点（从下标 1 开始）
int n;          // 节点总数
int is_first;   // 用于控制输出格式（每行数据之间用空格分隔，末尾无多余空格）

// 先序遍历：根 -> 左 -> 右
void preOrder(int root) {
    if (root > n) return; // 下标超过 n 说明该节点不存在，直接返回

    // 打印当前根节点
    if (is_first) {
        printf("%d", tree[root]);
        is_first = 0;
    } else {
        printf(" %d", tree[root]);
    }

    preOrder(root * 2);     // 递归左孩子
    preOrder(root * 2 + 1); // 递归右孩子
}

// 中序遍历：左 -> 根 -> 右
void inOrder(int root) {
    if (root > n) return;

    inOrder(root * 2);     // 递归左孩子

    // 打印当前根节点
    if (is_first) {
        printf("%d", tree[root]);
        is_first = 0;
    } else {
        printf(" %d", tree[root]);
    }

    inOrder(root * 2 + 1); // 递归右孩子
}

// 后序遍历：左 -> 右 -> 根
void postOrder(int root) {
    if (root > n) return;

    postOrder(root * 2);     // 递归左孩子
    postOrder(root * 2 + 1); // 递归右孩子

    // 打印当前根节点
    if (is_first) {
        printf("%d", tree[root]);
        is_first = 0;
    } else {
        printf(" %d", tree[root]);
    }
}

int main() {
    // 读入节点总数
    scanf("%d", &n);

    // 顺序读入完全二叉树，存入数组中
    for (int i = 1; i <= n; i++) {
        scanf("%d", &tree[i]);
    }

    // 1. 先序遍历
    is_first = 1;
    preOrder(1); // 从根节点（下标 1）开始递归
    printf("\n");

    // 2. 中序遍历
    is_first = 1;
    inOrder(1);
    printf("\n");

    // 3. 后序遍历
    is_first = 1;
    postOrder(1);
    printf("\n");

    return 0;
}
