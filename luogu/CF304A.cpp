#include <iostream>
#include <cmath>
using namespace std;

int a,b,c;
int n;
int ans;

int main(){
	cin>>n;
	for(int a=1;a<=n;a++){
		for(int b=a;b<=n;b++){
			int c=sqrt(a*a+b*b);
			if(c>n)
				break;
			if(a*a+b*b==c*c){
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}