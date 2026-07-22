#include<stdio.h>
#include<stdlib.h> 
int main(){
	int n;
	scanf("%d",&n);
	int *a=(int *)malloc(n*sizeof(int));
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int s[25];
	int top=-1;
	int idx=0;
	for(int i=1;i<=n;i++){
		s[++top]=i;
		printf("%d in\n",i);
		while(top>=0&&s[top]==a[idx]){
			printf("%d out\n",s[top]);
			idx++;
			top--;
		}
	}
}
