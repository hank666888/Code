#include<iostream>
using namespace std;

int a[210][210];

void doit(int n,int m,int x,int y){
    if(n==0||m==0)
        return ;
    if(n==1){
		for(int i=1;i<=m;i++){
			cout<<a[x][y]<<" ";
			y++;
		}
		return ;
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			cout<<a[x][y]<<" ";
			x++;
		}
		return ;
	}
    for(int i=1;i<=n-1;i++){
		cout<<a[x][y]<<" ";
		x++;
	}
	for(int i=1;i<=m-1;i++){
		cout<<a[x][y]<<" ";
		y++;
	}
	for(int i=1;i<=n-1;i++){
		cout<<a[x][y]<<" "; 
		x--;
	}
	for(int i=1;i<=m-1;i++){
		cout<<a[x][y]<<" ";
		y--;
	}
	doit(n-2,m-2,x+1,y+1);
}

int n,m;

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    doit(n,m,1,1);
    return 0;
}