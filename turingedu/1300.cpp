#include<iostream>
#include<cstdio>
using namespace std;

int ans;

void doit(int n,char x,char y,char z){
	if(n==1){
		printf("%d from %c to %c\n",n,x,z);
		ans++;
		return ;
	}
	doit(n-1,x,z,y);
	printf("%d from %c to %c\n",n,x,z);
	ans++;
	doit(n-1,y,x,z);
}

int main(){
	int n;
	cin>>n;
	doit(n,'A','B','C');
	cout<<ans<<endl;
	return 0;
}
