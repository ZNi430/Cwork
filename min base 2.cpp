#include <stdio.h>


int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        long long a;
        scanf("%lld", &a);
        if(a==0){
        	printf("2\n");
        	continue;
		} 
        for (int b = 2; b <= a + 1; b++) {
            
            // 1. 把 n 转换成 b 进制，存入数组
            long long digits[100]; // 10^6 在 2 进制下约 20 位，32 足够
            long long n_digits = 0;
            long long temp_a = a;
            
            while (temp_a > 0) {
                digits[n_digits] = temp_a % b; // 存入 b 进制的 "数字" (可能是10, 11等)
                temp_a /= b;
                n_digits++;
            }
            int hh[100]={0};
            // 2. 检查这个 'digits' 数组是否是一样的
            int is_palindrome = 1; // 假设是一样的
            for (int j = 0; j < n_digits ; j++) {
                hh[digits[j]]++;
                
                // if (digits[j] != digits[j+1]) {
                //     is_palindrome = 0; // 发现不相等
                //     break;
                // }
            }
            int m;
            for(int j=0;j<100;j++){
                if(hh[j]!=0){
                    m=hh[j];
                    break;
                }
            }
            for(int j=0;j<100;j++){
                if(hh[j]!=0&&m!=hh[j]){
                    is_palindrome = 0;
                    break;
                }
            }
            
            // 3. 如果是一样的，输出并跳出循环
            if (is_palindrome) {
                printf("%d\n", b);
                break; // 找到了最小的 b，停止搜索
            }
        }
    }
    return 0;
}
