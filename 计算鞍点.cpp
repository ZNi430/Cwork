#include<stdio.h>
int a[5][5];
int main(){
	int ma[5];
	for(int i=0;i<5;i++){
		int max=-1;
		for(int j=0;j<5;j++){
			scanf("%d",&a[i][j]);
			if(a[i][j]>max){
				max=a[i][j];
				ma[i]=j;
			}
		}
	}
	int mi[5];
	for(int j=0;j<5;j++){
		int min=999999;
		for(int i=0;i<5;i++){
			if(a[i][j]<min){
				min=a[i][j];
				mi[j]=i;
			}
		}
	}
	for(int i=0;i<5;i++){
		if(mi[ma[i]]==i){
			printf("%d %d %d",i,ma[i],a[i][ma[i]]);
			return 0;
		}
	}
	printf("not found");
}
