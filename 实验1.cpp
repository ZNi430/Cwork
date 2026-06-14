#include<stdio.h>
int main(){
	char s[100]="123\\011";
	printf("%d\n",sizeof("123\\011"));
	printf("%s\n",s);
	printf("%c\n",s[5]);
}
