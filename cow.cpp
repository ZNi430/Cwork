#include<stdio.h>
#include<stdlib.h>
int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m,p,k;
		scanf("%d %d %d %d",&n,&m,&p,&k);
		int *hhh=(int *)calloc((m+n-2),sizeof(int));
		int x1,x2,y1,y2;
		for(int i=0;i<p;i++){
			scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
			if(y1==y2){
				if(x1>x2){
					hhh[x2-1]++;
				}else{
					hhh[x1-1]++;
				}
			}else{
				if(y1>y2){
					hhh[m+y2-2]++;
				}else{
					hhh[m+y1-2]++;
				}
			}
		}
		qsort(hhh,m+n-2, sizeof(int), compare);
		if(hhh[k]==0){
			printf("0 ");
			for(int i=k;i>=0;i--){
				if(hhh[i]!=0){
					printf("%d\n",i);
					break;
				}
			}
		}else{
			int sum=0;
			for(int i=k;i<m+n-2;i++){
				sum+=hhh[i];
			}
			printf("%d\n",sum);
		}
	}
} 
