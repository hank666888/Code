#include<bits/stdc++.h>
using namespace std;

int n,ans,f[100001];
string a[100001];
stack<string> s;

bool ok(string s1,string s2)
{
	int j=0;
	for(int i=0;i<min(s1.size(),s2.size());i++)
	{
		if(s1[i]==s2[j])
		{
			j++;
		}
		else return false;
	}
	return true;
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	f[1]=1;
	s.push(a[1]);
	for(int i=2;i<=n;i++)
	{
		while(!s.empty()) {
			if(ok(s.top(), a[i])) {
				s.push(a[i]);
				break;
			}
			else
				s.pop();
		}
		if (s.empty())
			s.push(a[i]);
		if (s.size() > ans)
			ans = s.size();
	}
	cout<<ans<<endl;
	return 0;
}
