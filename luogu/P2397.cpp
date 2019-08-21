#include <iostream>
using namespace std;

int n,x,sum;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		if(a==x)
			sum++;
		else{
			if(sum==0)
				x=a;
			else
				sum--;
		}
	}
	cout<<x<<endl;
	return 0;
}