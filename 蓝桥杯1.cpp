#include<stdio.h>
#include<stdlib.h>
int cmp (const void *a,const void *b){
    return(*(int *)a-*(int *)b);
}
int main()
{
	int n,m,sum=0;
	int A=0,B=0,C=0;
	scanf("%d",&n);
	int *a=(int *)malloc(n*sizeof(int));
	int *b=(int *)malloc(n*sizeof(int));
	int *c=(int *)malloc(n*sizeof(int));
	for(int i=0;i<n;i++){
	    scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++){
	    scanf("%d",&b[i]);
	}
	for(int i=0;i<n;i++){
	    scanf("%d",&c[i]);
	}
	scanf("%d",&m);
	while(m--){
	    int x,y,z;
	    scanf("%d %d %d",&x,&y,&z);
	    A=(A+x)%n;
	    B=(B+y)%n;
	    C=(C+z)%n;
	    int ef[]={a[A],b[B],c[C]};
	    int cnt=0,tag=1;
	    //printf("%d\n",sum);
	        if(ef[0]==ef[1]&&ef[0]==ef[2])cnt=2;
	    if(cnt==2){
	        sum+=cnt;
	        continue;
	    }
	        if(ef[0]==ef[1]&&ef[0]!=ef[2])cnt=1;
	        if(ef[0]==ef[2]&&ef[0]!=ef[1])cnt=1;
	        if(ef[1]==ef[2]&&ef[0]!=ef[2])cnt=1;
	    for(int i=0;i<2;i++){
	        if((ef[i]+1)!=ef[i+1])tag=0;
	    }
	    if(tag){
	        sum+=2;
	        continue;
	    }
	    if(tag==0&&cnt==1){
	        sum+=1;
	        continue;
	    }
	    if(cnt==0){
	        tag=1;
	        qsort(ef,3,sizeof(int),cmp);
	        for(int i=0;i<2;i++){
	            if((ef[i]+1)!=ef[i+1])tag=0;
	        }
    	    if(tag){
    	        sum+=1;
    	        continue;
    	    }
	    }
	}
	printf("%d\n",100*sum);
	free(a);
	free(b);
	free(c);
}
