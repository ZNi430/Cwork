//别看了，他奶奶的又看错题目录了 

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int pailie(int a){
	int d=1;
	if(a==0){
		d=1;
	}else{
		for(int i=a;i>=1;i--){
			d*=i;
		}
	}
	
	return d;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		 
		scanf("%d",&n);
		int *len=(int *)malloc(n*sizeof(int));
		char **a=(char **)malloc(n*sizeof(char *));
		int *b=(int *)malloc(n*sizeof(int));
		for(int i=0;i<n;i++){
			a[i]=(char *)malloc(10*sizeof(char));
			scanf("%s",a[i]);
			len[i]=strlen(a[i]);
			int index[26]={0};
			for(int j=0;j<len[i];j++){
				index[a[i][j]-'a']++;
			}
			int fenzi=pailie(len[i]);
			for(int j=0;j<26;j++){
				if(index[j]==0){
					continue;
				}else{
					fenzi/=pailie(index[j]);
				}
			}
			b[i]=fenzi;
		}
		int max=0,tag=0;
		for(int i=0;i<n;i++){
			max=max<b[i]?b[i]:max;
		}
		for(int i=0;i<n;i++){
			if(b[i]==max){
				tag++;
			}
		}
		printf("%d\n",tag);
		for(int i=0;i<n;i++){
			if(b[i]==max){
				printf("%s \n",a[i]);
			}
		}
		if(t!=0)printf(" \n");
	}
}
