#include <iostream>
#include <string>
using namespace std;

int first[200010],s[200010];

int main(){
	string st;
	int n,ans=0;
	cin>>n;
	cin>>st;
	for(int i=0;i<n;i++){
		if(st[i]=='0')
			s[i+1]=s[i]-1;
		else
			s[i+1]=s[i]+1;
	}
	for(int i=1;i<=n;i++){
		if(first[s[i]+100000]==0)
			first[s[i]+100000]=i;
	}
	first[100000]=0;
	for(int i=2;i<=n;i++){
		ans=max(ans,i-first[s[i]+100000]);
	}
	cout<<ans<<endl;
	return 0;
}