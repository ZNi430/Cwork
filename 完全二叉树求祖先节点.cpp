#include <stdio.h>

int tree[505];      // 存储完全二叉树的节点（从下标 1 开始存储）
int ans[505];       // 临时代替栈存储祖先节点，用于最后逆序输出

int main() {
    int n;
    scanf("%d", &n);

    // 读入完全二叉树，从下标 1 开始存，方便利用 i/2 找父亲
    for (int i = 1; i <= n; i++) {
        scanf("%d", &tree[i]);
    }

    int target;
    scanf("%d", &target);

    // 寻找目标节点的下标
    int idx = -1;
    for (int i = 1; i <= n; i++) {
        if (tree[i] == target) {
            idx = i; // 如果有多个相同数据，以此处遍历到的最后一个为准
        }
    }

    // 从当前节点的双亲开始，一路上溯到根节点
    int count = 0;
    int curr = idx / 2; // 节点 i 的双亲节点下标是 i / 2
    while (curr > 0) {
        ans[count] = tree[curr]; // 记录祖先节点的值
        count++;
        curr = curr / 2;         // 继续往上一层（往根节点方向）找
    }

    // 题目要求从根节点往下输出祖先（如：38 14 44），所以我们需要逆序打印
    for (int i = count - 1; i >= 0; i--) {
        printf("%d", ans[i]);
        if (i > 0) {
            printf(" "); // 节点之间用空格分隔
        }
    }
    printf("\n");

    return 0;
}

