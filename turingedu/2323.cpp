#include <iostream>
#include <cmath>
using namespace std;

int a[110],b[110],tot,n,ans=1e9;

void dfs(int step,int sum){
	if(step==n+1){
		ans=min(ans,abs(tot-sum-sum));
		return ;
	}
	dfs(step+1,sum+a[step]);
	dfs(step+1,sum+b[step]);
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		tot+=a[i]+b[i];
	}
	dfs(1,0);
	cout<<ans<<endl;
	return 0;
}