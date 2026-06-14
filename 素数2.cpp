#include<stdio.h> 
int isPrime(int x) {
    if (x < 2) return 0;
    if(x%2==0) return 0;
    if(x%3==0) return 0;
    if(x%5==0) return 0;
    if(x%7==0) return 0;
    if(x%11==0) return 0;
    if(x%13==0) return 0;
    if(x%17==0) return 0;
    if(x%19==0) return 0;
    if(x%23==0) return 0;
    if(x%29==0) return 0;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}
int main(){
	int shu;
	scanf("%d",&shu);
	while(shu--){
		long long R,L;
		scanf("%lld %lld",&L,&R);
		int cnt=0;
		for(int i=L;i<=R;i++){
			if(isPrime(i))cnt++;
		}
		printf("%d\n",cnt);
	}
}
