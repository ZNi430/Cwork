#include<stdio.h>
int huiwen(int a){
	int x,y;
	x=a;
	y=a;
	int t=a;
	int index=1;
	
	while(t>9){
		x/=10;
		index*=10;
	}
	if(index%2!=0){
		return 0;
	}
	int tag=1;
	while(x!=0){
		if((x%10)!=(y/index)){
			tag=0;
			break;
		}
		x/=10;
		index/=10;
	} 
	if(tag){
		return 1;
	}else{
		return 0;
	}
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int a;
		scanf("%d",&a);
		for(int i=1;i<100000;i++){
			int sum=0,index=1;
			int t=a; 
			while(t!=0){			
				sum+=index*(t%i);
				index*=10;
				t/=i;
			}
			if(huiwen(sum)){
				printf("%d\n",i);
				break;
			}
		}
	}
}
