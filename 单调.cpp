#include<stdio.h>
int main(){
	int t ;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int a[32];
		for(int b=2;b<=n-1;b++){
			int t=n;
			int m=0;
			while(t>0){
				a[m++]=t%b;
				t/=b;
			}
			int tag=1;
			for(int i=0;i<m-1;i++){
				if(a[i]<=a[i+1]){
					tag=0;
					break;
				}
			}
			if(tag){
				printf("%d\n",b);
				break;
			}
		}
	}
}
