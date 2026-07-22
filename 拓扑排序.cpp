#include<stdio.h>
#include<string.h>
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	int adj[105][105]={0};
	int in_degree[105]={0};
	int visited[105]={0};
	for(int i=0;i<n;i++){
		int u,v;
		scanf("%d %d",&u,&v);
		if(adj[u][v]==0){
			adj[u][v]=1;
			in_degree[v]++;
		} 
		
	} 
	for(int step=0;step<m;step++){
		int found=-1;
		for(int i=1;i<=m;i++){
			if(in_degree[i]==0&&!visited[i]){
				found=i;
				break;
			}
		}
		if(found!=-1){
			visited[found]=1;
			printf("%d%c",found,(step==m-1)?'\n':' ');
			for(int i=1;i<=m;i++){
				if(adj[found][i]==1){
					in_degree[i]--;
				}
			}
		}
		
	}
}
