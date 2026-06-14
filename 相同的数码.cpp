#include<stdio.h>
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		long long hh;
		scanf("%lld",&hh);
		int tag;
		int a[64];
		int b,len=0;
		for(b=2;b<=100;b++){
			int len=0;
			long long n=hh;
			while(n!=0){
				a[len]=n%b;
				n/=b;
				len++;
			}
			tag=1;
			for(int i=0;i<len-1;i++){
				if(a[i]!=a[i+1]){
					tag=0;
					break;
				}
			}
			if(tag){
				printf("%d\n",b);
				break;
			}
		}
		if(tag==0){
			printf("0\n");
		}
	}
}
