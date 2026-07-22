#include <stdio.h>

int val[1005];   // 存储节点的值
int lch[1005];   // 存储左孩子的下标
int rch[1005];   // 存储右孩子的下标
int cnt = 0;     // 用来记录当前一共创建了多少个节点

// 插入函数：把值 v 插入到以 root 为根的子树中
int insert(int root, int v) {
    // 如果当前位置是0，说明是空位，就在这里新建一个节点
    if (root == 0) {
        cnt++;          // 节点计数加 1，作为新节点的下标
        val[cnt] = v;   // 存入数值
        lch[cnt] = 0;   // 初始没有左孩子
        rch[cnt] = 0;   // 初始没有右孩子
        return cnt;     // 返回这个新节点的下标
    }
    
    // 按照“左小右大”的二叉排序树规则往下找
    if (v < val[root]) {
        lch[root] = insert(lch[root], v); // 比当前节点小，往左边走
    } else {
        rch[root] = insert(rch[root], v); // 比当前节点大，往右边走
    }
    
    return root; // 返回当前子树的根
}

// 先序遍历：根 -> 左 -> 右
void preOrder(int root) {
    if (root == 0) return; // 走到空节点，直接返回
    
    printf("%d ", val[root]); // 1. 打印根节点
    preOrder(lch[root]);      // 2. 递归遍历左子树
    preOrder(rch[root]);      // 3. 递归遍历右子树
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    
    int root = 0; // 一开始树是空的，根节点下标为 0
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        root = insert(root, x); // 把读入的数一个个插进去
    }
    
    preOrder(root); // 从根节点开始先序遍历
    printf("\n");
    
    return 0;
}
