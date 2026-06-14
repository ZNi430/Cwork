#include<stdio.h>

// 使用更安全的组合数计算方法（避免大数阶乘）
long long comb(int n, int k) {
    if (k > n - k) k = n - k; // 利用对称性 C(n,k)=C(n,n-k)
    
    long long result = 1;
    for (int i = 1; i <= k; i++) {
        result = result * (n - k + i) / i;
    }
    return result;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int a, b;
        scanf("%d %d", &a, &b);
        
        if((a + b) % 2 != 0){
            printf("0\n");
            continue;
        }
        
        int k = (a + b) / 2;
        
        // 检查k是否在有效范围内
        if (k < 0 || k > a) {
            printf("0\n");
            continue;
        }
        
        printf("%lld\n", comb(a, k));
    }
    return 0;
}
