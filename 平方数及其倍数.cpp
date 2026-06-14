#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_RANGE 1000110
#define MAX_SQUARE 1100
int square_numbers[MAX_SQUARE];
int cnm[MAX_RANGE];

void hhh(){

	memset(cnm,0,sizeof(cnm));
	memset(square_numbers,0,sizeof(square_numbers));
	for(int i=2;i<=1000;i++){
		for(int k=i*i;k<MAX_RANGE;k+=i*i){
			cnm[k]=1;
		}
	}
	for(int i=1;i<MAX_RANGE;i++){
		square_numbers[i]=square_numbers[i-1];
		if(cnm[i]==1)square_numbers[i]++;
	}
}

int main(){
	hhh();
	int t;
	scanf("%d",&t);
	while(t--){
		int a,b;
		scanf("%d %d",&a,&b);
		printf("%d\n",square_numbers[b]-square_numbers[a-1]);
	}
}

