#include<stdio.h>
int he(int a[],int b[]){
	int sum[10];
	sum[1]=a[1]+a[2]+a[12]+b[1];
	sum[2]=a[2]+a[3]+b[1]+b[2];
	sum[3]=a[3]+a[4]+b[2]+a[5];
	sum[4]=a[12]+b[1]+a[11]+b[3];
	sum[5]=b[1]+b[2]+b[3]+b[4];
	sum[6]=b[2]+a[6]+b[4]+a[5];
	sum[7]=a[10]+b[3]+a[11]+a[9];
	sum[8]=b[3]+b[4]+a[9]+a[8];
	sum[9]=b[4]+a[8]+a[7]+a[6];
	int maxi=sum[1];
	for(int i=2;i<=9;i++){
		if(sum[i]>maxi)maxi=sum[i];
	}
	return maxi;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){//×î¶à¾Å¸ö2*2 
		int a[13],b[5],max_meizu,max[13],re;
		scanf("%d %d %d %d",&a[1],&a[2],&a[3],&a[4]);
		scanf("%d %d %d %d",&a[12],&b[1],&b[2],&a[5]);
		scanf("%d %d %d %d",&a[11],&b[3],&b[4],&a[6]);
		scanf("%d %d %d %d",&a[10],&a[9],&a[8],&a[7]);
		for(int i=1;i<=12;i++){
			max[i]=he(a,b);
			re=a[1];
			for(int j=1;j<12;j++){
				a[j]=a[j+1];
			}
			a[12]=re;
		}
		int maxa=max[1];
		for(int i=2;i<=12;i++){
			if(max[i]>maxa)maxa=max[i];
		}
		printf("%d\n",maxa);
	}
}
