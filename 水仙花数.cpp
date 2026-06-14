#include<stdio.h>
#include<math.h>
int main(){
	int t;
	while(scanf("%d",&t)!=EOF&&t!=0){
		int mask=1,x=t,index=1;
		while(x>9){
			x/=10;
			mask*=10;
			index++;
		}
		int y=t;
		int sum=0;
		for(int i=0;i<index;i++){
			
			sum+=pow(y%10,index)	;
			y/=10;
			
		}
		if(sum==t){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
	
}
