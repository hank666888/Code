#include <iostream>
using namespace std;

int sx,sy;

void doit(int n,int c,int x,int y){
	if(n==1){
		if(x==sx&&y==sy)
			cout<<c+1<<endl;
		return ;
	}
	if(n==0)
		return ;
	for(int i=1;i<=n-1;i++){
		if(x==sx&&y==sy){
			cout<<c+1<<endl;
			return ;
		}
		c++;
		y++;
	}
	for(int i=1;i<=n-1;i++){
		if(x==sx&&y==sy){
			cout<<c+1<<endl;
			return ;
		}
		c++;
		x++;
	}
	for(int i=1;i<=n-1;i++){
		if(x==sx&&y==sy){
			cout<<c+1<<endl;
			return ;
		}
		c++;
		y--;
	}
	for(int i=1;i<=n-1;i++){
		if(x==sx&&y==sy){
			cout<<c+1<<endl;
			return ;
		}
		c++;
		x--;
	}
}

int n,c;

int main(){
	cin>>n>>sx>>sy;
	int x=1,y=1;
	int t=min(min(sy,n-sy+1),min(sx,n-sx+1));
	for(int i=1;i<=t-1;i++){
		c=c+(n-1)*4;
		n=n-2;
		x++,y++;
	}
	doit(n,c,x,y);
	return 0;
}