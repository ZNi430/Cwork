#include<stdio.h>
#include<string.h>
int main(){
	char s[201];
	while(scanf("%s",s)!=EOF){
		getchar();
		int d=strlen(s);
		int kongge=0,zhonglei=0;
		int zimu[26]={0};
		for(int i=0;i<d;i++){
			if(s[i]==' '){
				kongge++;
			}else{
				zimu[s[i]-'a']++;
			}
		}
		for(int i=0;i<26;i++){
			if(zimu[i]!=0)zhonglei++;
		}
		if(zhonglei>10||kongge>9){
			printf("No\n");
		}else{
			printf("Yes\n");
		}
	} 
} 
