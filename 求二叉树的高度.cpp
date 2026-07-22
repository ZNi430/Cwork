#include <stdio.h>

int lch[1005];  // 存储左孩子的下标
int rch[1005];  // 存储右孩子的下标

// 求高度函数：计算以 root 为根的子树的高度
int getHeight(int root) {
    // 如果当前节点是 -1，说明是空树，高度为 0
    if (root == -1) {
        return 0;
    }

    int left_h = getHeight(lch[root]);  // 求出左子树的高度
    int right_h = getHeight(rch[root]); // 求出右子树的高度

    // 树的高度为左右子树高度的最大值，再加上当前节点自己（1层）
    if (left_h > right_h) {
        return left_h + 1;
    } else {
        return right_h + 1;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int root = -1;
    for (int i = 0; i < n; i++) {
        int id, l, r;
        scanf("%d %d %d", &id, &l, &r);
        
        // 题目明确说明：输入数据的第一行是整棵树的根节点
        if (i == 0) {
            root = id;
        }
        
        // 记录当前节点的左右孩子
        lch[id] = l;
        rch[id] = r;
    }

    // 计算并打印整棵二叉树的高度
    int ans = getHeight(root);
    printf("%d\n", ans);

    return 0;
}
