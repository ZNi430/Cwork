#include <stdio.h>
#include <stdlib.h>

// qsort 的比较函数，用于初始排序
int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int main() {
    int n;
    int a[1005];
    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // 1. 初始阶段：先把所有单质能量从小到大排个序
    qsort(a, n, sizeof(int), cmp);

    int total_energy = 0;
    int start = 0; // start 记录当前还未被合并的最小元素的下标

    // 2. 贪心合并：n 个元素需要合并 n-1 次
    for (int i = 0; i < n - 1; i++) {
        // 每次合并当前最小的两个元素
        int sum = a[start] + a[start + 1];
        total_energy += sum; // 累加消耗的能量

        // 3. 核心：把新生成的化合物“插入”到后面合适的位置，保持后面的数组依然有序
        int j = start + 1;
        while (j < n - 1 && sum > a[j + 1]) {
            a[j] = a[j + 1]; // 比新合成能量小的元素往前挪
            j++;
        }
        a[j] = sum; // 把新能量填入正确的位置

        start++; // 两个元素合二为一，有效起点往后移一位
    }

    // 4. 输出最终总能量
    printf("%d\n", total_energy);

    return 0;
}
