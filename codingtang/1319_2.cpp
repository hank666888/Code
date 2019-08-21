#include <iostream>
using namespace std;

const int MAXN=1010,MAXM=1010;

struct node
{
	int x,y;
};

int n,m;
node fa[MAXN][MAXM];

void init(int n,int m){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			fa[i][j]=(node){i,j};
}

node find(node d){
	if(fa[d.x][d.y].x==d.x&&fa[d.x][d.y].y==d.y)
		return d;
	return fa[d.x][d.y]=find(fa[d.x][d.y]);
}

void unite(node d1,node d2){
	d1=find(d1);
	d2=find(d2);
	if(d1.x==d2.x&&d1.y==d2.y)
		return ;
	fa[d1.x][d1.y]=d2;
}

bool same(node d1,node d2){
	d1=find(d1);
	d2=find(d2);
	return d1.x==d2.x&&d1.y==d2.y;
}

int main(){
	cin>>n>>m;
	init(n,n);
	for(int i=1;i<=m;i++){
		int x,y;
		char d;
		cin>>x>>y>>d;
		node t1=(node){x,y},t2;
		if(d=='D')
			t2=(node){x+1,y};
		if(d=='R')
			t2=(node){x,y+1};
		if(same(t1,t2)){
			cout<<i<<endl;
			return 0;
		}
		else
			unite(t1,t2);
	}
	cout<<"draw"<<endl;
	return 0;
}