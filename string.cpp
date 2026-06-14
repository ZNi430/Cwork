#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		char chuan[10001],b[27];
		scanf("%s",chuan);
		scanf("%s",b);
		int len_a=strlen(chuan);
		int len_b=strlen(b);
		int count=0;
		int *hhh=(int *)calloc((len_a+1),sizeof(int));
		for(int i=0;i<len_a;i++){
			int index=0; 
			for(int j=0;j<len_b;j++){
				if(chuan[i]==b[j]){
					index=1;
					break;
				}
			}
			if(index==1){
				count++;
				hhh[i] = count; 
			}else{
				hhh[i]=count;
				count=0;
			}
		}
		int maxi=0;
		for(int i=0;i<len_a;i++){
			if(maxi<hhh[i])maxi=hhh[i];
		}
		printf("%d\n",maxi);
		free(hhh);
	}
}
