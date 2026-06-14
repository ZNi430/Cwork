#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
	char line[1001];
	while(scanf("%s",line)!=EOF){
		int d=strlen(line);
		int *anny=(int *)malloc((d+1)*sizeof(int));
		int *jilu=(int *)calloc((d+1),26);
		for(int i=0;i<d;i++){
			anny[i]=line[i]-'a';
		}
		for(int i=0;i<d;i++){
			jilu[anny[i]]++;
		}
		int tag=0;
		if(d%2==0){
			for(int i=0;i<26;i++){
				if(jilu[i]%2!=0){
					tag=1;
					break;
				}
			}
		}else{
			int ji=0,ou=0;
			for(int i=0;i<26;i++){
//				if(jilu[i]>0&&jilu[i]%2==0)ou++;
				if(jilu[i]%2!=0)ji++;
			}
			if(ji!=1){
				tag=1;
			}
		}
		if(tag){
			printf("No\n");
		}else{
			printf("Yes\n");
		}
	}
}
