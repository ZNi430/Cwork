#include <stdio.h>
#include <string.h>

char pre[1005]; // 存储先序遍历字符串
char in[1005];  // 存储中序遍历字符串

// 递归函数：通过先序和中序的下标范围，输出后序遍历
// preL, preR 表示当前子树在先序序列中的左右边界下标
// inL, inR   表示当前子树在中序序列中的左右边界下标
void solve(int preL, int preR, int inL, int inR) {
    // 递归边界：如果下标交错，说明是空树，直接返回
    if (preL > preR) {
        return;
    }

    // 1. 先序遍历的第一个字符就是根节点
    char root = pre[preL];

    // 2. 在中序遍历中寻找根节点的位置 k
    int k;
    for (k = inL; k <= inR; k++) {
        if (in[k] == root) {
            break;
        }
    }

    // 3. 计算左子树的节点个数
    int numLeft = k - inL;

    // 4. 先递归左子树
    solve(preL + 1, preL + numLeft, inL, k - 1);

    // 5. 再递归右子树
    solve(preL + numLeft + 1, preR, k + 1, inR);

    // 6. 最后输出根节点（后序遍历的特点：左右根）
    printf("%c", root);
}

int main() {
    // 读入先序和中序遍历序列
    scanf("%s", pre);
    scanf("%s", in);

    int len = strlen(pre);

    // 传入整棵树的初始下标范围进行求解
    solve(0, len - 1, 0, len - 1);
    printf("\n");

    return 0;
}
