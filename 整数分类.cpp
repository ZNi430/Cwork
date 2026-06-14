#include<stdio.h>
#include<math.h>
#include<string.h>
int leijia(char *line,int d){
	int sum=0;
	for(int i=0;i<d;i++){
		sum+=line[i]-'0';
	}
	return sum;
}
int main(){
//	int a=1;
//	for(int i=1;i<=500;i++){
//		a*=10;
//	}
	char line[502];//数组大小不合理,a的值是10^500，这远超过任何计算机的内存容量，实际上只需要存储最多501个字符（包括结束符）。
	while(scanf("%s",line)!=EOF){
		if(line[0]=='0')break;
		int d=strlen(line);
		int o=leijia(line,d);
		if(o>=10){
		
			do{
			
				int sum=0;
				while(o>0){
					sum+=o%10;
					o/=10;
				}
				o=sum;
			}while(o>=10);
		}
		printf("%d\n",o);
	}
}
