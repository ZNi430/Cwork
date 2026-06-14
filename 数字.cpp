#include<stdio.h>
int he (int a){
	int sum=0;
	do{
		sum+=a%10;
		a/=10;
	}while(a>0);
	return sum;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int x;
		scanf("%d",&x);
		int i; 
		for(i=x;i>=1;i--){
			if(i%he(i)==0){
				break;
			}
		}
		if(i==0){
			i++;
		}
		printf("%d\n",i);
		
	}
}
