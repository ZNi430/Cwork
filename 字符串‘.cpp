#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main(){
	//延长一倍，依次滑动，计算差量，存入数组，排序后输出第一位
	int t;
	scanf("%d",&t);
	while(t--){
		char T[2002],C[1001];
		scanf("%s",T);
		scanf("%s",C);
		int len =strlen(C);
		strcat(T,T);
		int *hhh=(int *)malloc(len*sizeof(int));
		//i为偏转 ,j为C数组位置 
		for(int i=0;i<len;i++){
			int sum=0;
			for(int j=0;j<len;j++){
				sum+=(C[j]-T[j+i]+26)%26>(T[j+i]-C[j]+26)%26?(T[j+i]-C[j]+26)%26:(C[j]-T[j+i]+26)%26;
			}
			hhh[i]=sum+i;
		}
		//接下来是排序
		qsort(hhh, len, sizeof(int), compare); 
		printf("%d\n",hhh[0]);
		free(hhh); 
	}
}
