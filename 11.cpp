#include<stdio.h>
#define MAXN 1000005 
long long f[MAXN]; 

int main(){
    for(int i = 0; i < MAXN; i++) f[i] = i;
    for(int i = 2; i < MAXN; i++){
        if(f[i] == i){ 
            for(int j = i; j < MAXN; j += i){
                f[j] = f[j] / i * (i - 1);
            }
        }       
    }
    //Ç°×ººÍ 
    for(int i = 2; i < MAXN; i++) f[i] += f[i-1];
    int shu;
    if(scanf("%d",&shu)!=1) return 0;
    while(shu--){
        long long R,L;
        scanf("%lld %lld",&L,&R);
        if(R >= MAXN) R = MAXN - 1; 
        printf("%lld\n", f[R] - f[L-1]);
    }
    return 0;
}
