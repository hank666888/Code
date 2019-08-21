#include <iostream>
using namespace std;

const int MAXN=1e5+10;

int a[MAXN];
int n,w;

int lowbit(int x){
	return x&(-x);
}

void add(int x,int d){
	while(x<=n){
		a[x]+=d;
		x+=lowbit(x);
	}
}

int sum(int x){
	int ret=0;
	while(x>0){
		ret+=a[x];
		x-=lowbit(x);
	}
	return ret;
}

int main(){
	cin>>n;
	cin>>w;
	while(w--){
		char c;
		int a,b;
		cin>>c>>a>>b;
		if(c=='x')
			add(a,b);
		else
			cout<<sum(b)-sum(a-1)<<endl;
	}
	return 0;
}