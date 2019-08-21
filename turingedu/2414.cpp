#include <iostream>
using namespace std;

int a[110][110];

void doit(int n,int c,int x,int y){
	if(n==0)
		return ;
	if(n==1){
		a[x][y]=c;
		return ;
	}
	for(int i=1;i<=n-1;i++){
		a[x][y]=c;
		c++;
		x++;
	}
	for(int i=1;i<=n-1;i++){
		a[x][y]=c;
		c++;
		y--;
	}
	for(int i=1;i<=n-1;i++){
		a[x][y]=c;
		c++;
		x--;
	}
	for(int i=1;i<=n-1;i++){
		a[x][y]=c;
		c++;
		y++;
	}
	doit(n-2,c,x+1,y-1);
}

int n;

int main(){
	cin>>n;
	doit(n,1,1,n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}