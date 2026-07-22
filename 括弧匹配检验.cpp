#include<stdio.h>
#include<string.h>
int main(){
	char a[300];
	int top=-1;
	char x[300];
	scanf("%s",x);
	int idx=0;
	int lenx=strlen(x);
	while(idx<lenx){
		if(top!=-1&&((a[top]=='['&&x[idx]==']')||(a[top]=='('&&x[idx]==')'))){
			top--;
		}else{
			a[++top]=x[idx];
		}
		idx++;
	}
	if(top==-1)printf("OK");
	else printf("Wrong");
}
