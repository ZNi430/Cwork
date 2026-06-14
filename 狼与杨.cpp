#include<stdio.h>
#define MOD 1000000007
long long ways[1001][1001];
void ddd(){
	ways[0][0]=1;
	for(int i=1;i<1001;i++){
		for(int j=1;j<=i;j++){
			ways[i][j]=(ways[i-1][j-1]+(long long)j*ways[i-1][j])%MOD;
		}
	}
}
int main(){
	ddd();
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m,k;
		scanf("%d %d %d",&n,&m,&k);
		long long total=0;
		for(int i=1;i<k;i++){
			if (wolf_rooms > n || sheep_rooms > m) continue;
			total+=ways[n][i]*ways[m][k-i]%MOD;
			total%=MOD;
		}	
		printf("%lld\n",total);
	}
}
