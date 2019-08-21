#include<iostream>
#include<cstdio>
using namespace std;

int ans=0,st[110],ed[110],n;
char ch[4]={' ','A','B','C'};

void doit(int x,int y){
	if(st[x]==y)
		return ;
	for(int i=x-1;i>=1;i--)
		doit(i,6-st[x]-y);
	cout<<"move "<<x<<" from "<<ch[st[x]]<<" to "<<ch[y]<<endl;
	st[x]=y;
	ans++;
}

int main(){
	cin>>n;
	for(int i=1;i<=3;i++){
		int m;
		cin>>m;
		for(int j=1;j<=m;j++){
			int x;
			cin>>x;
			st[x]=i;
		}
	}
	for(int i=1;i<=3;i++){
		int m;
		cin>>m;
		for(int j=1;j<=m;j++){
			int x;
			cin>>x;
			ed[x]=i;
		}
	}
	for(int i=n;i>=1;i--)
		doit(i,ed[i]);
	cout<<ans<<endl;
	return 0;
} 
