#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
	char name[505];
}hhh;
int cmp(const void *a,const void *b){
	hhh *x=(hhh *)a;
	hhh *y=(hhh *)b;
	return strcmp(x->name ,y->name );
}
int main(){
	int n,m;
	scanf("%d",&n);
	hhh a[205];
	for(int i=0;i<n;i++){
		scanf("%s",a[i].name );
	}
	scanf("%d",&m);
	for(int i=n;i<m+n;i++){
		scanf("%s",a[i].name );
	}
	qsort(a,n+m,sizeof(hhh),cmp);
	char b[505];
	strcpy(b,a[0].name );
	for(int i=1;i<n+m;i++){
		if(strcmp(b,a[i].name )==0){
			printf("%s ",b);
			
		}else{
			strcpy(b,a[i].name );
		}
	}
}
