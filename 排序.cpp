#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int comparea(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
int compared(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		char b;
		char a='A';
		scanf("%d %c",&n,&b);
		int *p=(int *)malloc(n*sizeof(int));
		for(int i = 0; i < n; i++){
		    scanf("%d", &p[i]);
		}
		if(b=='A'){
			qsort(p, n, sizeof(int), comparea);
		}else{
			qsort(p, n, sizeof(int), compared);
		}
		for(int i=0;i<n;i++){
			printf("%d",p[i]);
			if(i!=n-1){
				printf(" ");
			}else printf("\n");
		}
		free(p);
	}
}
