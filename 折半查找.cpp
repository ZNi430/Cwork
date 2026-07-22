#include<stdio.h>
int main(){
	int n,data;
	scanf("%d %d",&n,&data);
	int a[10005];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int l=0,r=n-1;
	int cnt=0;
	while(l<=r){
		int mid=(l+r)/2;
		cnt++;
		if(a[mid]==data){
			printf("%d\n",cnt);
			return 0;
		}else if(a[mid]<data){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	printf("0\n");
	return 0;
}
