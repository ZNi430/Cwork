#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	int t,count=1;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d %d",&n,&m);
		char *str=(char*)malloc((n)*sizeof(char));
		char *arr=(char*)malloc((n)*sizeof(char));
		for(int i=0;i<n;i++){
			str[i]='A'+i;
		}
		printf("%s\n",str);
		printf("#%d:\n",count++);
		while(m--){
			int c;
			scanf("%d",&c);
			strcpy(arr,str);
			if(c<0){
				c=-c;
				for(int i=0;i<c;i++){			
					for(int j=0;j<n;j++){
						int yi=arr[0];
						if(j<n-1)arr[j]=arr[j+1];//Õ˘◊Û“∆ 
						arr[n-1]=yi;
					}
				}
			}
			if(c>0){
				for(int i=0;i<c;i++){			
					for(int j=n-1;j>=0;j--){
						int yi=arr[n-1];
						if(j>0)arr[j]=arr[j-1];//Õ˘”““∆ 
						arr[0]=yi;
					}
				}
			}
			printf("%s\n",arr);
		}
	}	
}
