#include<stdio.h>
#include<string.h>
//只考虑了一种连接顺序
//befab 和 babef 长度都是5，但 babef 的字典序更小，所以正确答案应该是 babef。
//比较过程非常简单，就是从两个字符串的 第一个字符开始，一对一地向后比较.
//比较ascll码 
int main(){
	char a[200];
	char b[200];
	while(1){
		scanf("%s",a);
		scanf("%s",b);
		int x=strlen(a);
		int y=strlen(b);
		int tag=1,t=0;
		for(int i=0;i<x;i++){
			
			
				if(a[i]==b[0]){
					for(int k=1;k<=x-1-i;k++){
						if(a[i+k]!=b[k]){
							tag=0;
							break;
						}
					}
					if(tag){
						t=x-i;
						goto out;
					}
					tag=1;
				}
			
		}
		out:printf("%s",a);
		for(int i=t;i<y;i++){
			printf("%c",b[i]);
		}
		printf("\n");
	}
}
