#include<stdio.h>
int main(){
	char zimu;
	int shizi[53][107];//最多有26*2行，4*26-1列，但为使第一行的角标对应为一，需要+1 
	while(scanf("%c",&zimu)!=EOF){
		int num=zimu-'A'+1;
		int l,r;//l为列，r为行
		int l_max=num*4-1,r_max=num*2;
		//我打算先填入空格
		
		//两边的空格处理 
		for(r=1;r<=r_max;r++){
			for(l=2*num-1;l>=1;l--){
				shizi[r][l]=' ';
				shizi[r][l_max-l+1]=' ';
			}
		}
		//中间空格 
		for(r=num+1;r<=r_max-1;r++){
			for(l=num+1;l<=2*num-1;l++){
				shizi[r][l]=' ';
				shizi[r][l_max-l+1]=' ';
			}
			shizi[r][2*num]=' ';
		}
		
		//下面处理字母
		
		//先搞一个三角形的 
		for(r=1;r<=num;r++){
			for(l=2*num;l>=2*num-r+1;l--){
				shizi[r][l]=l+r+'A'-1-2*num;//这是美妙的
				shizi[r][l_max-l+1]=shizi[r][l];
			}
		}
		//下面两个三角形也差不多的
		for(r=1+num;r<=2*num;r++){
			for(l=num;l>=num-(r-num)+1;l--){
				shizi[r][l]=shizi[r-num][l+num];
				shizi[r][2*num-l]=shizi[r][l];
				shizi[r][l_max+1-l]=shizi[r][l];
				shizi[r][l_max+1-2*num+l]=shizi[r][l];
			}
		}
	
		//打印
		for(r=1;r<=r_max;r++){
			for(l=1;l<=l_max;l++){
				printf("%c",shizi[r][l]);
				if(r==r_max&&l==2*num-1)printf(" ");
			}
			printf("\n");
		}	 
	}
}
