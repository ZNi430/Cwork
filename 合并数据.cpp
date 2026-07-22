#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a, const void *b) {
		return (*(int *)a - *(int *)b);
}
int main(){
	int m,n;
	scanf("%d",&m);
	int *a=(int *)malloc(m*sizeof(int));
	for(int i=0;i<m;i++){
		scanf("%d",&a[i]);
	}
	scanf("%d",&n);;
	a = (int *)realloc(a, (m + n) * sizeof(int));

	for(int i=0;i<n;i++){
		scanf("%d",&a[m+i]);
	}
	qsort(a,n+m,sizeof(int),cmp);
	printf("%d ",a[0]);
	for(int i=1;i<m+n;i++){
		if(a[i]!=a[i-1])printf("%d ",a[i]);
	}
}
