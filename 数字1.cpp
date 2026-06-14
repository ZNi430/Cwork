#include<stdio.h>
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		int count=0;
		scanf("%d",&n);
		int sum=n;
		while(n!=0){
			sum=1;
			while(n%10!=0){
				count++;
				n--;
			}
			while(n!=0){
				sum+=sum*10+n%10;
				n/=10;
			}
			if(sum!=1)count++;
			n=sum;
		}
		printf("%d\n",count);
	}
}
