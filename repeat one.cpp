#include<stdio.h>
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int m;
		scanf("%d",&m);
		if(m>999989||m%2==0){
			printf("0\n");
			continue;
		}
		int n,tag=1;
		long long sum=0;
		for(int i=1;i<=500000;i++){
			
			sum+=sum*10+1;//方法需要简化，看文档 
			if(sum%m==0){
				n=i;
				tag=0;
				break;
				
			}
		}
		if(tag){
			printf("0\n");
		}else{
			printf("%d",n);
		}
		
	}
}
