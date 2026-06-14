#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char s[][11]={"ab","abc","cab","aaa","b","ba","aa"};
int cmp(const void *a,const void *b){
	return strcmp((char *)a,(char *)b);
}
void out (int sz){
	int i;
	for(i=0;i<sz;i++)puts(s[i]);
	puts("---------");
}
int main(){
	int sz=sizeof(s)/sizeof(s[0]);
	out(sz);
	qsort(s,sz,sizeof(s[0]),cmp);
	out(sz);
}
