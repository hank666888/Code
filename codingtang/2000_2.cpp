#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int> > pq;
int n,ans;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		pq.push(a);
	}
	for(int i=1;i<=n-1;i++){
		int a=pq.top();
		pq.pop();
		int b=pq.top();
		pq.pop();
		ans+=a+b;
		pq.push(a+b);
	}
	cout<<ans<<endl;
	return 0;
}