#include <iostream>
#include <queue>
using namespace std;

priority_queue< int, vector<int>, greater<int> > pq;

int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		if(k==1){
			int x;
			cin>>x;
			pq.push(x);
		}
		else if(k==2)
			cout<<pq.top()<<endl;
		else 
			pq.pop();
	}
	return 0;
}