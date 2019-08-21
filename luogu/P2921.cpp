#include <iostream>
using namespace std;

int n,next[100010];

bool vis[100010];

int dfs(int now,int num){
	cout<<num<<endl;
	vis[now]==true;
	if(vis[next[now]])
		return num;
	dfs(next[now],num+1);
	vis[now]=false;
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>next[i];
	for(int i=1;i<=n;i++){
		cout<<dfs(i,1)<<endl;
	}
	return 0;
}