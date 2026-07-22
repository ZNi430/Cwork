#include<stdio.h>
#include<string.h>
char pre[1005];
char in[1005];

void solve(int prel,int prer,int inl,int inr){
	if(prel>prer)return ;
	char root=pre[prel];
	int k;
	for(k=inl;k<=inr;k++){
		if(in[k]==root){
			break;
		}
	}
	int numleft=k-inl;
	solve(prel+1,prel+numleft,inl,k-1);
	solve(prel+numleft+1,prer,k+1,inr);
	printf("%c",root);
}
int main(){
	scanf("%s",pre);
	scanf("%s",in);
	int len =strlen(pre);
	solve(0,len-1,0,len-1);
}
