#include<stdio.h>
int cmp(const void *a,const void *b){
	return *(int *)a-*(int *)b;
}
int main(){
	int n;
	scanf("%d",&n);
	int a[3005];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	qsort(a,n,sizeof(int),cmp);
	int start=0
	int tot=0;
	for(int i=0;i<n-1;i++){
		int sum =a[start]+a[start+1];
		tot+=sum;
		int j=start+1;
		while(j<n-1&&sum>a[j+1]){
			a[j]=a[j+1];
			j++;
		}
		a[j]=sum;
		start++;
	} 
	printf("%d",tot);
}
