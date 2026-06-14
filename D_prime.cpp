#include<stdio.h>
int is_prime(long long n) {
    if (n <= 1) return 0;
    if (n == 2 || n == 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    
    // 只需要检查到 sqrt(n)，且步进为 6 (检查 i 和 i+2)
    // 这样可以跳过所有 2 和 3 的倍数，提高效率
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return 0;
    }
    return 1;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int temp=n;
		int index=0;
		for(int i=2;i*i<=temp;i++){
			if(temp%i==0){
				if(is_prime(n/i)&& (n/i != i)){
					printf("Yes\n");
					index=1;
					break;
				}
				while(temp%i==0){
					temp/=i;
				}
			}
		}
		if(index==0)printf("No\n");
	}
}
