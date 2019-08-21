#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int n;
	cin>>n;
	for(int x=2;x<=sqrt(n);x++)
		if(n%x==0){
			cout<<n/x<<endl;
			return 0;
		}
	cout<<1<<endl;
	return 0;
} 
