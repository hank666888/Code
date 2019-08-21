#include <iostream>
using namespace std;

int a,b;

int ans;

int main(){
	cin>>a>>b;
	for(int i=a;i<=b;i++)
		if(i%4==0&&(i%100!=0||i%400==0))
			ans++;
	cout<<ans<<endl;
	return 0;
}