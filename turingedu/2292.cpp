#include <iostream>
using namespace std;

int n;

int need,now;

int main(){	
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		need=min(need,now+a);
		now=now+a;
	}
	cout<<0-need<<endl;
	return 0;
}