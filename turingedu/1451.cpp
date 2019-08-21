#include <iostream>
#include <string>
using namespace std;

int first[2000010],s[2000010];

int main(){
	string st;
	int n,ans=0;
	cin>>st;
	n=st.size();
	for(int i=0;i<n;i++){
		if(st[i]=='G')
			s[i+1]=s[i]-1;
		else
			s[i+1]=s[i]+1;
	}
	for(int i=1;i<=n;i++){
		if(first[s[i]+1000000]==0)
			first[s[i]+1000000]=i;
	}
	first[1000000]=0;
	for(int i=2;i<=n;i++){
		ans=max(ans,i-first[s[i]+1000000]);
	}
	cout<<ans<<endl;
	return 0;
}