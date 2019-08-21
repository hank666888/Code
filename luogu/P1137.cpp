#include <iostream>
#include <vector>
using namespace std;

std::vector<int> G[100010];

int n,m,dp[100010];

int dfs(int x){
	if(dp[x]!=-1)
		return dp[x];
	dp[x]=1;
	for(int i=0;i<G[x].size();i++)
		dp[x]=max(dp[x],dfs(G[x][i])+1);
	return dp[x];
}

int main(){
	cin>>n>>m;
	fill(dp,dp+1+n,-1);
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		G[y].push_back(x);
	}
	for(int i=1;i<=n;i++)
		cout<<dfs(i)<<endl;
	return 0;
}