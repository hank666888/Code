#include <iostream>
using namespace std;

const int MAXN=5010,mod=80112002;

int rd[MAXN],cd[MAXN],G[MAXN][MAXN],f[MAXN],n,m,ans;

int dfs(int x){
	if(!cd[x])
		return f[x]=1;
	int sum=0;
	for(int i=1;i<=n;i++){
		if(G[x][i]){
			sum+=f[i]?f[i]:dfs(i);
			sum%=mod;
		}
	}
	return f[x]=sum;
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		G[v][u]=1;
		rd[u]++;
		cd[v]++;
	}
	for(int i=1;i<=n;i++)
		if(!rd[i])
			ans=(ans+dfs(i))%mod;
	cout<<ans<<endl;
	return 0;
}