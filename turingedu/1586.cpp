#include <iostream>
using namespace std;

int n;

int a[210][210];

int ans;

int b;

void js(int x,int y){
	for(int k=1;k<=min(n-x+1,n-y+1);k++){
		bool flag1=false;
		for(int i=x;i<=x+k-1;i++){
			for(int j=y;j<=y+k-1;j++)
				if(a[i][j]!=b){
					flag1=true;
					break;
				}
			if(flag1)
				break;
		}
		if(flag1)
			break;
		ans=max(ans,k);
	}
}

int main(){
	cin>>n;
	cin>>b;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]==b){
				js(i,j);
			}
		}
	}
	cout<<ans<<endl;
}