#include<stdio.h>
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		int idx=1;
		for(int i=0;i<n-1;i++){
			printf("-");
		}
		printf("\n");
		for(int i=1;i<n/2;i++){
			int d=idx*2+1;
			for(int j=1;j<=idx-1;j++){
				printf(" ");
			}
			printf("\\");
			for(int j=1;j<=n-d;j++){
				if(idx==1){
					printf(" ");
				}else{
					printf("*");
				}
			}
			printf("/\n");
			idx++;
		}
		idx--;
		for(int i=1;i<n/2;i++){
			
			int d=idx*2+1;
			int l=0;
			for(int j=1;j<idx;j++){
				printf(" ");
				l++;
			}
			printf("/");
			l++;
			for(int j=1;j<=n-d;j++){
				l++;
				if(l==n/2){
					printf("*");
				}else{
					printf(" ");
				}
			}
			printf("\\\n");
			idx--;
		} 
		for(int i=0;i<n-1;i++){
			printf("-");
		}
	}
}
