#include <stdio.h>
#include <stdlib.h>

// 1. 因为不需要返回值，建议改成 void
void xianxv(int i, int *a, int t){
    if(i >= t) return; // 终止条件
    
    printf("%d ", a[i]); // 访问根节点
    
    // 2. 修正下标公式（从0开始的二叉树顺序存储规律）
    xianxv(i * 2 + 1, a, t); // 左孩子
    xianxv(i * 2 + 2, a, t); // 右孩子
}

int main(){
    int t;
    if (scanf("%d", &t) != 1) return 1; // 增加严谨性，判断输入
    
    int *a = (int *)malloc(sizeof(int) * t);
    for(int i = 0; i < t; i++){
        scanf("%d", &a[i]);
    }
    
    xianxv(0, a, t); // 从0号下标（根节点）开始遍历
    
    free(a); // 别忘了释放内存的好习惯
    return 0;
}
