#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
	char name[21];
	int num;
}hhh;
int cmp(const void *a,const void *b ){
	hhh *x=(hhh *)a;
	hhh *y=(hhh *)b;
	if(x->num !=y->num ){
		return y->num - x->num; 
	}
	return strcmp(x->name ,y->name );
}
int main(){
	int n;
	scanf("%d",&n);
	hhh *a=(hhh *)malloc(n*sizeof(hhh));
	for(int i=0;i<n;i++){
		scanf("%s",a[i].name);
		scanf("%d",&a[i].num);
	}
	qsort(a,n,sizeof(hhh),cmp);
	for(int i=0;i<n;i++){
		printf("%s %d\n",a[i].name ,a[i].num );
	}
} 
