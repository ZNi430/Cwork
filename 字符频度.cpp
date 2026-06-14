#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
	char s[1001];
	while(scanf("%s",s)!=EOF){
		int d=strlen(s);
		int *pp=(int *)malloc(d*sizeof(int));
		int zimu[24]={0};
		for(int i=0;i<d;i++){
			pp[i]=s[i]-'a';
			zimu[pp[i]]++;
		}
		int min=100000;
		for(int i=0;i<24;i++){
			if(zimu[i]==0)continue;
			min=min>zimu[i]?zimu[i]:min;
		}
		printf("%d",min);
		for(int i=0;i<24;i++){
			if(min==zimu[i]){
				printf(" %c",'a'+i);
			}
			
		}
		printf("\n");
	}
}
