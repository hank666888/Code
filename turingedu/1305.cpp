#include<iostream>
using namespace std;

void doit(int n,char x,char y,char z){
	if(n==0)
		return ;
	doit(n-1,x,z,y);
	cout<<n<<" "<<x<<" "<<z<<endl;
	doit(n-1,y,x,z);
}

int main(){
	int n;
	cin>>n;
	doit(n,'A','C','B');
	return 0;
} 
