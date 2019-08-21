#include <iostream>
#include <algorithm>
using namespace std;

int t;
int n,a[20010];
int f[25010];

int main(){
	cin>>t;
	while(t--){
		int ans=0,max_v=0;
		cin>>n;
		for(int i=1;i<=25000;i++)
			f[i]=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			max_v=max(max_v,a[i]);
		}
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++){
			if(f[a[i]])
				continue;
			ans++;
			f[a[i]]=true;
			for(int j=a[i];j<=max_v;j++)
				if(f[j-a[i]])
					f[j]=1;
		}
		cout<<ans<<endl;
	}
	return 0;
}