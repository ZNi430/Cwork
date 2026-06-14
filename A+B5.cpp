#include<stdio.h>
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int a,b;
		scanf("%d %d",&a,&b);
		int sum=0,index=1;
		while(a!=0||b!=0){
			sum+=index*((a%10+b%10)%10);
			index*=10;
			a/=10;
			b/=10;
		}
		printf("%d\n",sum);
	}
}
