#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	int *a=(int *)malloc((n+1)*sizeof(int));
//	for(int i=1;i<=n;n++){
//		scanf("%d",&a[i]);
//	}
	getchar();
	char line[10001];
	fgets(line,10002,stdin);
	int count=0;
	char *token=strtok(line," \n");
	while(token!=NULL&&count<n){
		sscanf(token,"%d",&a[count+1]);
		count++;
		token=strtok(NULL," \n");
	}
	int d,b,c;
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&d,&b,&c);
		for(int j=d;j<=b;j++){
			a[i]+=c;
		}
	}
	for(int i=1;i<=n;i++){
		printf("%d\n",a[i]);
	}
	a[0]=0;
	for(int i=1;i<=n;i++){
		a[i]=a[i]+a[i-1];
		printf("%d",a[i]);
		if(i!=n){
			printf(" ");
		}
	}
}
