#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> pq;

int n,k,x;

int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>x;
		pq.push(x);
	}
	while(pq.size()>1){
		int a=pq.top();
		pq.pop();
		int b=pq.top();
		pq.pop();
		pq.push((a+b)/k);
	}
	cout<<pq.top()<<endl;
	return 0;
}