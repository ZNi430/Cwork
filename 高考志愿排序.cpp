#include<stdio.h>
#include<stdlib.h>
typedef struct{
	int id;
	int yuwen;
	int shuxue;
	int yingyu;
	int z;
}hhh;
int cmp(const void *a,const void *b){
	hhh *x=(hhh *)a;
	hhh *y=(hhh *)b;
	if(x->z !=y->z ){
		return y->z-x->z;
	}
	if(x->yuwen !=y->yuwen ){
		return y->yuwen-x->yuwen;
	}
	if(x->shuxue !=y->shuxue ){
		return y->shuxue-x->shuxue;
	}
	return y->yingyu-x->yingyu;
}
int main(){
	int m,n;
	scanf("%d %d",&m,&n);
	hhh *a=(hhh *)malloc(m*sizeof(hhh));
	for(int i=0;i<m;i++){
		a[i].id =i+1;
		scanf("%d %d %d",&a[i].yuwen ,&a[i].shuxue  ,&a[i].yingyu );
		a[i].z=a[i].yuwen+a[i].shuxue+a[i].yingyu;
	}
	qsort(a,m,sizeof(hhh),cmp);
	for(int i=0;i<n;i++){
		printf("%d ",a[i].id );
	}
}
