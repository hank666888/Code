#include <iostream>
#include <queue>
using namespace std;

int n,a[300010];

priority_queue< int, vector<int>, greater<int> > pq;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pq.push(a[i]);
	}
	int ans=0;
	while(pq.size()>1){
		int a1=pq.top();
		pq.pop();
		int a2=pq.top();
		pq.pop();
		ans+=a1+a2;
		pq.push(a1+a2);
	}
	cout<<ans<<endl;
	return 0;
}