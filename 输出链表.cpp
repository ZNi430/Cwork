#include<stdio.h>
#include<stdlib.h>
typedef struct{
	int v;
	int id;
}aaa;

int main(){
	int l,n;
	scanf("%d %d",&l,&n);
	aaa * a=(aaa *)malloc((l+1)*sizeof(aaa));
	for(int i=1;i<=l;i++){
		scanf("%d %d",&a[i].v,&a[i].id);
	}
	int cnt=0;
	int b[1005];
	while(n!=0){
		b[cnt++]=a[n].v;
		n=a[n].id;
	}
	for(int i=cnt-1;i>=0;i--){
		printf("%d ",b[i]);
	}
}
