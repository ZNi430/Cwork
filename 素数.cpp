#include<stdio.h>
#include<math.h>
#include<stdlib.h> 
int main(){
	int n;
	scanf("%d",&n);
	int *a=(int *)calloc(n,sizeof(int));
	

	for(int i=2;i<n;i++){
		if(a[i]==0){
			for(int j=2;j*i<n;j++){
				a[i*j]=1;
			}
		}
	}
	for(int i=2;i<n;i++){
		if(a[i]==0){
			printf("%d\n",i);
		}
		
	}
}
