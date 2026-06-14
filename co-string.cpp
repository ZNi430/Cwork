#include<stdio.h>
#include<math.h>
#include<string.h>
int main(){
	int t;
	scanf("%d",&t);
	
	while(t--){
		char s[2001];
		scanf("%s",s);
		int len=strlen(s);
		int maxi=0;
		for(int i=0;i<len;i++){
			for(int j=i+1;j<len;j++){//先找到第一个相同的数 
				if(s[i]==s[j]){
					int d=j-i-1,tag=1;
					if(d==0)maxi=2>maxi?2:maxi;
					for(int k=1;k<=d;k++){//在检查它们中间和后面的数是否相同 
						if(s[i+k]!=s[j+k]){
							tag=0;
							break;
						}
					}
					if(tag){
						maxi=(d+1)*2>maxi?(d+1)*2:maxi;
					}
				}
			}
		}
		printf("%d\n",maxi);
	}
}
