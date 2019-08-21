#include <iostream>
#include <queue>
using namespace std;

int n,m,maxx,count,ans[10010];
priority_queue<int> q;

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int a,b,c;
		cin>>a>>b>>c;
		for(int x=1;x<=m;x++){
			int f=a*x*x+b*x+c;
			if(q.size()<m)
				q.push(f);
			else{
				if(q.top()>f){
					q.pop();
					q.push(f);
				}
				else
					break;
			}
		}
	}
	for(int i=1;i<=m;i++){
		ans[m-i+1]=q.top();
		q.pop();
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}