#include<stdio.h>
#include<stdlib.h>
int compare (const void *a,const void *b){
    return (*(int *)a-*(int *)b);
}
int main(){
    int t;
    scanf("%d",&t);
    int sum=0;
    int m=t*3;
    int *a=(int *)malloc(sizeof(int)*m);
    for(int i=0;i<m;i++){
        scanf("%d",&a[i]);
    }
     qsort(a,m,sizeof(int),compare);
     for(int i=0;i<m;i+=3){
         sum+=(a[i]-a[i+1])*(a[i]-a[i+1])+(a[i+1]-a[i+2])*(a[i+1]-a[i+2]);
     }
     printf("%d\n",sum);
}
