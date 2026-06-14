#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		char a[100001];
		scanf("%s",a);
		int len =strlen(a);
		int num;
		for(int i=1;i<len;){
			if(a[i]>=a[i-1])i++;
			else {
				num=a[i-1]-'0';
				num=num+1<9?num+1:9;
				strncpy(a+i-1,a+i,len-i);
				sprintf(a+len-1,"%d",num);
			}
		}
		printf("%s\n",a);
	}
}
