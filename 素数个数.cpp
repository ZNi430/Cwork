#include<stdio.h>
long long gcd(long long a,long long int b){
	return b==0?a:gcd(b,a%b);
}
int main(){

long long n[1000000000]={0};//0ÊÇËØÊý 
long long f[1000000000];
for(long long i=2;i<1000000000;i++){
	if(n[i]==0){
		for(long long p=2;p*i<1000000000;p++){
			long long j=i*p; 
			n[j]=1;
			if(n[p]==0)f[p]=p-1;
			else if (gcd(i,p)==1)f[j]=f[p]*(i-1);
			else f[j]=f[p]*(i);
		}
	}		
}
int shu;
scanf("%d",&shu);
while(shu--){
	long long R,L;
	scanf("%lld %lld",&L,&R);
	printf("%lld\n",f[R]-f[L-1]);
}

}
