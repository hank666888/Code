#include <iostream>
using namespace std;

int sum[100010],n,a[100010],k,ans;


int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){	
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=k;i<=n;i++)
		ans=max(ans,sum[i]-sum[i-k]);
	cout<<ans<<endl;
	return 0;
}