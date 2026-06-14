#include<stdio.h>
#include<string.h>
#include<math.h>
int main(){
	char s[101];
	while(scanf("%s",s)!=EOF){
		int len=strlen(s);
		if(len==1){
			printf("0\n");
			continue;
		}
		
		int tag=1;
		for(int i=2;i<=2021;i++){//iÊÇ½øÖÆ 
			int sum=0;
			for(int j=len-1,k=0;j>=0;j--,k++){
				sum+=(s[j]-'0')*pow(i,k);
			} 
			if(sum==2021){
				printf("%d\n",i);
				tag=0;
				break;
			}
		}
		if(tag){
			printf("0\n");
		}
	}
}
