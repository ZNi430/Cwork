#include<stdio.h>
#include<stdlib.h>
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	int *a=(int *)malloc(n*sizeof(int));
	int *b=(int *)malloc(m*sizeof(int));
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<m;i++){
		scanf("%d",&b[i]);
	}
	int idx=m-1;
	for(int i=n-1;i>=0;i--){
		if(idx>=0&&i==b[idx]){
			idx--;
		}else{
			printf("%d ",a[i]);
		}
	}
}
