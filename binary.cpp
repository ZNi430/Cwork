#include<stdio.h>
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		long long a,t;
		scanf("%lld",&a);
		int b[34];
		t=a;
		int index=0;
		while(t!=0){
			b[index]=t%2;
			t/=2;
			index++;
		}
		int tag=0,max=0;
		for(int i=0;i<index;i++){
			if(b[i]==1){
				tag++;
			}else{
				max=max<tag?tag:max;
				tag=0;
			}
		}
		printf("%d\n",tag);
	}
} 
