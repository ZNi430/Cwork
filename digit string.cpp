#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int main(){
	char s[32];
	int n;
	while(scanf("%s",s)!=EOF){
		scanf("%d",&n);
		int len=strlen(s);
		int *a=(int *)malloc(len*sizeof(int));
		int max=0; 
		for(int i=0;i<len;i++){
			if(s[i]>='A'&&s[i]<='F'){
				a[i]=s[i]-'A'+10;
			}else{
				a[i]=s[i]-'0';
			}
			max=max<a[i]?a[i]:max;
		}
		
		int tag=1;
		for(int b=2;b<=16;b++){
			int sum=0;
			for(int i=0;i<len;i++){
				sum+=a[i]*pow(b,len-1-i);
			}
			if(sum==n&&b>max){
				printf("%d\n",b);
				tag=0;
				break;
			}
		}
		if(tag){
			printf("Impossible\n");
		}
	}
}
