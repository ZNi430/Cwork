#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_RANGE 1000199
#define MAX_SQRT 1000100
int is_prime_small[MAX_RANGE];
int primes[MAX_SQRT];
int prime_count=0;
int inter_prime_count=0;
int inter_prime[MAX_SQRT]={0};

void get_inter_primes(){

	//初始化假设都是素数 
	memset(is_prime_small,1,sizeof(is_prime_small));
	
	is_prime_small[0] = is_prime_small[1] = 0;//0，1不是素数
	for (int i = 2; i < MAX_SQRT; i++) {
	        if (is_prime_small[i]) {
	            primes[prime_count++] = i; // 记录素数
	            // 筛掉倍数
	            for (int j = 2 * i; j < MAX_SQRT; j += i) {
	                is_prime_small[j] = 0;
	            }
	        }
	}
	
	for(int i=2;i<prime_count;i++){
		inter_prime[inter_prime_count++]=	(primes[i]+primes[i-1])/2;
	}
}

int main(){
	get_inter_primes();
	int t;
	scanf("%d",&t);
	while(t--){
		int a,b;
		int count=0;
		scanf("%d %d",&a,&b);
		for(int i=0;i<inter_prime_count;i++){
			if(inter_prime[i]<=b&&inter_prime[i]>=a){
				count++;
			}
			if(inter_prime[i]>b)break;
		}
		printf("%d\n",count);
	} 
}
