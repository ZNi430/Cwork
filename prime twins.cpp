#include<stdio.h>

#define MAX_RANGE 5000001

int new_prime[MAX_RANGE];//Ä¬ÈÏ0ÎªËØÊý 
int is_prime[MAX_RANGE];
int twin_prime[MAX_RANGE];
int cnt=0;

void find(){
	for(int i=2;i<MAX_RANGE;i++){
		if(new_prime[i]==0){
			is_prime[cnt++]=i;
			if(cnt>=2&&is_prime[cnt-1]==is_prime[cnt-2]+2){
				twin_prime[is_prime[cnt-1]]++;
			}
			for(int j=i*i;j<MAX_RANGE;j+=i){
				new_prime[j]=1;
			}
		}
	} 
	for(int i=1;i<MAX_RANGE;i++){
		twin_prime[i]+=twin_prime[i-1];
	}
}

int main(){
	find(); 
	int t;
	scanf("%d",&t);
	while(t--){
		int a,b;
		scanf("%d %d",&a,&b);
		if(b < a + 2) {
            printf("0\n");
        } else {
			printf("%d\n",twin_prime[b]-twin_prime[a+1]);
		}
	}
}
