#include<stdio.h>
#include <stdlib.h>
int main(){
	int a,b;
	int d;
	scanf("%d %d",&a,&b);
	scanf("%d",&d);
	for(int i=0;i<d;i++){
		printf("%d %d\n",i%a+1,i%b+1);
	}
} 
