#include <iostream>
using namespace std;

int a[11][11];

//n:当前层的规模	c:计数的自然数 x,y:起笔的位置 
void doit(int n,int c,int x,int y){
	if(n==1){
		a[x][y]=c;
		return ;
	}
	if(n==0)
		return ;
	for(int i=1;i<=n-1;i++){
		a[x][y]=c;
		c++;
		y++;
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
	doit(n-2,c,x+1,y+1);
}

int n;

int main(){
	cin>>n;
	doit(n,1,1,1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}