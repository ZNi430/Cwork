#include<stdio.h>
int a[10005];
int bit[32];
long long get_current_or() {
    long long res = 0;
    for (int i = 0; i < 31; i++) {
        if (bit[i] > 0) {
            res |= (1LL << i);
        }
    }
    return res;
}
int main(){
	int n,k;
	while(scanf("%d %d",&n,&k)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			
		}
		
		long long max=0;
		for(int i=0;i<k;i++){
			for(int j=0;j<31;j++){
				if((a[i]>>j)&1){
					bit[j]++;
				}
			}
		}
		max=get_current_or();
		for(int i=k;i<n;i++){
			long long current=0;
			for(int j=0;j<31;j++){
				if((a[i]>>j)&1){
					bit[j]++;
				}
				if((a[i-k]>>j)&1){
					bit[j]--;
				}
			}
			current=get_current_or();
			if(max<current)max=current;
		}
		printf("%lld",max);	
		
	}
} 
