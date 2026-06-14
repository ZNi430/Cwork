#include<stdio.h>

#define MAX_RANGE 10000000
#define PRIME_COUNT 700000
#define MAX_LEN 5000000 // 素数串长度大约是470万，开500万足够

char new_prime[MAX_RANGE];
int is_prime[PRIME_COUNT];
char prime_string[MAX_LEN]; 

// 新增优化用的变量
int pos[MAX_LEN];       // 存储所有数字出现的位置
int start_pos[11];      // 记录0-9每个数字在pos数组中的起始存储位置
int count_digit[10];    // 记录0-9每个数字的总数量

int cnt = 0;
int count = 0; // 这是素数串的总长度

void gain(){
    // 1. 筛选素数
    for(int i=2;i<MAX_RANGE;i++){
        if(new_prime[i]==0){
            is_prime[cnt++]=i;
            for(int j=2*i;j<MAX_RANGE;j+=i){
                new_prime[j]=1;
            }
        }
    }
    
    // 2. 生成素数串
    for(int i=0;i<cnt;i++){
        int temp = is_prime[i];
        int stack[15];
        int top = 0;
        
        if(temp == 0) stack[top++] = 0;
        while(temp > 0){
            stack[top++] = temp % 10;
            temp /= 10;
        }
        
        while(top > 0){
            if(count < MAX_LEN){
                prime_string[count++] = stack[--top];
            }
        }
    }
}

// 新增：构建位置索引，为了快速查询
void build_index() {
    // 第一步：统计每个数字出现了多少次
    for (int i = 0; i < count; i++) {
        count_digit[(int)prime_string[i]]++;
    }

    // 第二步：计算每个数字在pos数组中的起始位置（前缀和思路）
    start_pos[0] = 0;
    for (int i = 1; i <= 10; i++) { // 用到10是为了方便计算边界
        start_pos[i] = start_pos[i-1] + count_digit[i-1];
    }
    
    // 复制一份起始位置用于填充，因为填充时下标会移动
    int current_idx[10];
    for(int i=0; i<10; i++) current_idx[i] = start_pos[i];

    // 第三步：把每个数字出现的下标 i 存入 pos 数组
    for (int i = 0; i < count; i++) {
        int d = prime_string[i];
        pos[current_idx[d]++] = i;
    }
}

// 新增：二分查找函数
// 查找数字 d 在位置 limit 之前出现了多少次
int find_cnt(int limit, int d) {
    if (count_digit[d] == 0) return 0;
    
    int L = start_pos[d];
    int R = start_pos[d+1] - 1;
    int ans = -1; // 记录找到的最后一个小于 limit 的下标位置
    
    // 在 pos 数组的 [start_pos[d], start_pos[d+1]-1] 范围内二分
    // 我们要找有多少个位置值是小于 limit 的
    int low = L, high = R;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(pos[mid] < limit){
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    if (ans == -1) return 0;
    return ans - L + 1;
}

int main(){
    gain();
    build_index(); // 必须先构建索引
    
    int t;
    if(scanf("%d",&t)!=1) return 0;
    while(t--){
        int l,r,d;
        scanf("%d %d %d",&l,&r,&d);
        
        int real_l = l - 1;
        if(real_l < 0) real_l = 0;
        
        int real_r = r;
        if(real_r > count) real_r = count;

        // 原来的 for 循环直接被减法替代，速度快几十万倍
        if (real_l >= real_r) {
            printf("0\n");
        } else {
            int ans = find_cnt(real_r, d) - find_cnt(real_l, d);
            printf("%d\n", ans);
        }
    }
    return 0;
}
