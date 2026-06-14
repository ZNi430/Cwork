#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main(){
	char s[1001];
	while(scanf("%s",s)!=EOF){
		int len=strlen(s);
		long long sum=0;
		int *a=(int *)malloc(len*sizeof(int));
		for(int i=0;i<len;i++ ){
			a[i]=s[i]-'a';
		}
	
		sum+=(int)pow(26,len)%1000000007;
	
		for(int i=0;i<len;i++){
			sum+=(a[i]*(int)pow(26,len-i-1))%1000000007;
		}
		printf("%lld\n",sum%1000000007);
		
	}
}
