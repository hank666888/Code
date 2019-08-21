#include <iostream>
#include <queue>
using namespace std;

priority_queue< int, vector<int>, greater<int> > q;
int n,x,y;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x;
		if(x==1){
			cin>>y;
			q.push(y);
		}
		else if(x==2)
			cout<<q.top()<<endl;
		else
			q.pop();
	}
	return 0;
}