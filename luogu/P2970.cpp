#include <iostream>
#include <algorithm>
using namespace std;

struct cow
{
	int begin,end;
};

cow c[100010];

bool cmp(cow a,cow b){
	if(a.end!=b.end)
		return a.end<b.end;
	return a.begin<b.begin;
}

int n;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>c[i].begin>>c[i].end;
	sort(c+1,c+1+n,cmp);
	int ans=1,t=c[1].end;
	for(int i=2;i<=n;i++){
		if(c[i].begin>=t){
			ans++;
			t=c[i].end;
		}
	}
	cout<<ans<<endl;
	return 0;
}