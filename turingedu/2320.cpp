#include <iostream>
#include <algorithm>
using namespace std;

int n,b,a[110],ans=1e9;

bool used[110];

void dfs(int sum,int step){
	if(sum>=b){
		ans=min(ans,sum-b);
		return ;
	}
	if(step>n)
		return ;
	dfs(sum,step+1);
	dfs(sum+a[step],step+1);
}

int main(){
	cin>>n>>b;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+1+n);
	dfs(0,1);
	cout<<ans<<endl;
	return 0;
}