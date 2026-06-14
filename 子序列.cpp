#include<stdio.h>
#include<string.h>
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		char a[201],b[201];
		scanf("%s",a);
		scanf("%s",b);
		int c=strlen(a),d=strlen(b);
		
		int i=0,j=0;
		for(i,j;i<c&&j<d;i++){
			if(a[i]==b[j]){
				j++;
			}			
		}
		if(j==d){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}	

}
