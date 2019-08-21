#include <iostream>
using namespace std;

int a[1010][1010];

void doit(int n,int m,int c,int x,int y){
	if(n==0||m==0)
		return ;
	if(n==1){
		for(int i=1;i<=m;i++){
			a[x][y]=c;
			c++;
			y++;
		}
		return ;
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			a[x][y]=c;
			c++;
			x++;
		}
		return ;
	}
	for(int i=1;i<=m-1;i++){
		a[x][y]=c;
		c++;
		y++;
	}
	for(int i=1;i<=n-1;i++){
		a[x][y]=c;
		c++;
		x++;
	}
	for(int i=1;i<=m-1;i++){
		a[x][y]=c;
		c++;
		y--;
	}
	for(int i=1;i<=n-1;i++){
		a[x][y]=c;
		c++;
		x--;
	}
	doit(n-2,m-2,c,x+1,y+1);
}

int n,m;

int main(){
	cin>>n>>m;
	doit(n,m,1,1,1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}