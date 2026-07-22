#include <stdio.h>

// 1. 核心数据结构（完全沿用你的定义）
int val[1005];   // 存储节点的值
int lch[1005];   // 存储左孩子的下标
int rch[1005];   // 存储右孩子的下标
int cnt = 0;      // 用来记录当前一共创建了多少个节点

// 2. 递归构建二叉树
int buildTree() {
    char ch;
    // " %c" 前面加个空格，可以自动跳过换行符和空格，防错能力更强
    if (scanf(" %c", &ch) != 1 || ch == '.') {
        return 0; // 0 代表空节点
    }
    
    cnt++; // 创建新节点
    int curr = cnt;
    
    val[curr] = ch; // 字符直接存入 int 数组
    
    // 递归建立左子树和右子树，并把返回的房间号（下标）存起来
    lch[curr] = buildTree();
    rch[curr] = buildTree();
    
    return curr; // 返回当前节点的下标
}

// 3. 中序遍历（左 -> 根 -> 右）
void inorder(int root) {
    if (root == 0) return; // 空节点直接返回
    
    inorder(lch[root]);         // 走左边
    printf("%c", (char)val[root]); // 打印根（强转成 char 输出）
    inorder(rch[root]);         // 走右边
}

// 4. 后序遍历（左 -> 右 -> 根）
void postorder(int root) {
    if (root == 0) return; // 空节点直接返回
    
    postorder(lch[root]);        // 走左边
    postorder(rch[root]);        // 走右边
    printf("%c", (char)val[root]); // 打印根
}

int main() {
    // 第一步：建树，获取根节点下标
    int rootID = buildTree();
    
    // 第二步：输出中序遍历
    inorder(rootID);
    printf("\n");
    
    // 第三步：输出后序遍历
    postorder(rootID);
    printf("\n");
    
    return 0;
}
