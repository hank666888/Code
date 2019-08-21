#include <iostream>
#define MAXN 1010
using namespace std;

int n,m,k;

int ans;

int G[MAXN][MAXN],cow[MAXN];

int cango[MAXN];

bool visited[MAXN];

void dfs(int x){
	visited[x]=true;//标记已访问过
	cango[x]++;//计数器++
	for(int i=1;i<=n;i++)
		if(!visited[i]&&G[x][i])//没访问并且能到达的
			dfs(i);				//进行深搜
}

int main(){
	cin>>k>>n>>m;
	for(int i=1;i<=k;i++){
		cin>>cow[i];
	}
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		G[u][v]=1;
	}
	for(int i=1;i<=k;i++){
		dfs(cow[i]);//对每一个牛的所在点进行深度搜索
		fill(visited,visited+1+n,false);//fiil是iostream库里的一个函数，功能跟memset差不多
	}									//之所以要清零，是因为你还要继续深搜
	for(int i=1;i<=n;i++)
		if(cango[i]==k)
			ans++;//统计答案
	cout<<ans<<endl;//输出
	return 0;//完结撒花！
}