#include<stdio.h>
#include<string.h>

#define MAX_RANGE 1000100
int small_primes[MAX_RANGE];
int primes[MAX_RANGE];
int prime_count=0;
// int double_primes_count=0; // 这个变量没用到，可以删掉
int cnm[MAX_RANGE]; // 变量名建议优化，例如 is_double_prime
int double_primes[MAX_RANGE];

void search_double_primes(){
    // 初始化
    memset(small_primes, 1, sizeof(small_primes));
    small_primes[0] = small_primes[1] = 0;
    
    // 筛素数
    for(int i=2; i<MAX_RANGE; i++){
        if(small_primes[i]){
            primes[prime_count++] = i;
            // 注意：i*2 对于 10^6 不会溢出，但如果范围更大要小心
            for(int k=i*2; k<MAX_RANGE; k+=i){
                small_primes[k] = 0;
            }
        }
    }
    
    // 寻找双素数
    for(int i=0; i<prime_count; i++){
        for(int k=i+1; k<prime_count; k++){ // 如果题目算 2*2=4，这里改成 k=i
            long long val = (long long)primes[i] * primes[k]; // 【关键修改】防止溢出
            
            if(val >= MAX_RANGE){ // 【关键修改】判断越界
                break;
            }else{
                cnm[val] = 1;
            }
        }
    }
    
    // 前缀和处理
    for(int i=1; i<MAX_RANGE; i++){
        double_primes[i] = double_primes[i-1] + cnm[i];
    }
}

int main(){
    search_double_primes();
    int t;
    if(scanf("%d", &t) != 1) return 0; // 增加读取检查是个好习惯
    while(t--){
        int a, b;
        scanf("%d %d", &a, &b);
        // 确保 a-1 不越界（虽然题目通常 a>=1，但防御性编程更好）
        int lower = (a-1 < 0) ? 0 : double_primes[a-1];
        printf("%d\n", double_primes[b] - lower);
    }
    return 0;
}
