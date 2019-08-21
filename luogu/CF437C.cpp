#include <iostream>
using namespace std;

int n,m;

int ans;

int d[10010];

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>d[i];
	}	
	while(m--){
		int x,y;
		cin>>x>>y;
		ans+=min(d[x],d[y]);
	}
	cout<<ans<<endl;
	return 0;
}