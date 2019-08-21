#include<iostream>
using namespace std;

int n,ans1,ans2,c2,c5;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int t=i;
		while(t%2==0){
			c2++;
			t/=2;
		}
		t=i;
		while(t%5==0){
			c5++;
			t/=5;
		}
	}
	ans1=min(c2,c5);
	c2=0,c5=0; 
	for(int i=n;i>=1;i-=2){
		int t=i;
		while(t%2==0){
			c2++;
			t/=2;
		}
		t=i;
		while(t%5==0){
			c5++;
			t/=5;
		}
	}
	ans2=min(c2,c5);
	cout<<ans1<<" "<<ans2<<endl;
	return 0;
} 
