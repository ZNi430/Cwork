#include<stdio.h>
#include<string.h>//有点问题 
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		char a[101];
		char b[101];
		scanf("%s",a);
		scanf("%s",b);
		int x=strlen(a);
		int y=strlen(b);
		int tag=1,count=0;
		for(int i=0;i<x;i++){
			for(int j=0;j<y;j++){
				if(a[i]==a[j]){
					count++;
					for(int k=1;k<x-i&&k<y-j;k++){
						if(a[i+k]==b[j+k]){
							count++;
						}else{
							break;
						}
					}
				}
			}
		}
		printf("%d\n",count);
	}
}
