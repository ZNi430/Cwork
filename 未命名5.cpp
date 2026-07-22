#include<stdio.h>
int rch[1005];
int lch[1005];

int high(int root){
	if(root==-1)return 0;
	int hl=high(lch[root]);
	int hr=high(rch[root]);
	if(hl>hr)return hl+1;
	else return hr+1;
	
}

int main(){
	int n;
	scanf("%d",&n);
	int root=-1;
	for(int i=1;i<=n;i++){
		int id,r,l;
		scanf("%d %d %d",&id,&r,&l);
		if(root==-1)root=id;
		lch[id]=l;
		rch[id]=r;
	}
	int ans=high(root);
	printf("%d",ans);
}
