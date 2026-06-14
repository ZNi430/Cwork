#include<stdio.h>

int zi[10010];
int mu[10010];

int gcd(int x,int y){
    return y==0?x:gcd(y,x%y);
}
void hhh(){
    for(int i=0;i<10010;i++){
        if(i%2==0){
            zi[i]=i;
            mu[i]=i+1;
        }else{
            zi[i]=i+2;
            mu[i]=i+1;
        }
    }
}

int main(){
    hhh();
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b;
        scanf("%d %d",&a,&b);
        int zi_new=mu[a-1]*zi[b]-mu[b]*zi[a-1];
        int mu_new=mu[b]*mu[a-1];
        if(zi_new*mu_new<0)printf("-");
        if(zi_new<0)zi_new=-zi_new;
        if(mu_new<0)mu_new=-mu_new;
        int n=gcd(zi_new,mu_new);
        printf("%d/%d\n",zi_new/n,mu_new/n);
    }
}
