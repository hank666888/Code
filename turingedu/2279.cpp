#include <iostream>
using namespace std;

int sx,sy;

void doit(int n,int c,int x,int y){
	if(n==1){
		if(x==sx&&y==sy)
			cout<<c<<endl;
		return ;
	}
	if(n==0)
		return ;
	for(int i=1;i<=n-1;i++){
		if(x==sx&&y==sy){
			cout<<c<<endl;
			return ;
		}
		c++;
		y++;
	}
	for(int i=1;i<=n-1;i++){
		if(x==sx&&y==sy){
			cout<<c<<endl;
			return ;
		}
		c++;
		x++;
	}
	for(int i=1;i<=n-1;i++){
		if(x==sx&&y==sy){
			cout<<c<<endl;
			return ;
		}
		c++;
		y--;
	}
	for(int i=1;i<=n-1;i++){
		if(x==sx&&y==sy){
			cout<<c<<endl;
			return ;
		}
		c++;
		x--;
	}
	doit(n-2,c,x+1,y+1);
}

int n;

int main(){
	cin>>n>>sx>>sy;
	doit(n,1,1,1);
	return 0;
}