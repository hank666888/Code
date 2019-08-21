#include <iostream>
#include <queue>
using namespace std;

const int INF=1e9;

priority_queue<int> q1;
priority_queue<int, vector<int>, greater<int> > q2;

int n,x,y;

int main(){
	cin>>n;
	cin>>x;
	q1.push(x);
	q2.push(INF);
	cout<<x<<endl;
	for(int i=3;i<=n;i+=2){
		cin>>x>>y;
		if(x>y)
			swap(x,y);
		int q1_top=q1.top();
		int q2_top=q2.top();
		if(y<q1_top){
			q1.pop();
			q2.push(q1_top);
			q1.push(x);
			q1.push(y);
		}
		else if(x>q2_top){
			q2.pop();
			q1.push(q2_top);
			q2.push(x);
			q2.push(y);
		}
		else{
			q1.push(x);
			q2.push(y);
		}
		cout<<q1.top()<<endl;
	}
	return 0;
}