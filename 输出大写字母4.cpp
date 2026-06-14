#include<stdio.h>
#include<string.h>
int main(){
	int t;
	scanf("%d",&t);
	getchar(); 
	while(t--){
		char a[81];
		int zimu[26]={0};
		fgets(a,81,stdin);
		int len=strlen(a);
		int tag=1;
		for(int i=0;i<len;i++){
			if(a[i]>='A'&&a[i]<='Z'){
				if(zimu[a[i]-'A']==0){
					printf("%c",a[i]);
					zimu[a[i]-'A']++;
					tag=0;
				}
			}
		}
		if(tag)printf("Not Found");
		printf("\n");
	} 
} 
