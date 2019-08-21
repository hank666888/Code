#include <iostream>
using namespace std;

const int MAXN=1010,INF=1e8;

int n,m;

int dis1[MAXN][MAXN],dis2[MAXN][MAXN];

void init(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dis1[i][j]=dis2[i][j]=INF;
}//一定要初始化！还有INF不要赋太大！否则floyd时相加容易溢出！

void floyd1(){
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis1[i][j]=min(dis1[i][j],dis1[i][k]+dis1[k][j]);
}

void floyd2(){
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis2[i][j]=min(dis2[i][j],dis2[i][k]+dis2[k][j]);
}

int main(){
	cin>>n>>m;
	init();
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		dis1[u][v]=dis1[v][u]=1;
	}//读入+建铁路网
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			if(i==j)
				continue;
			if(dis1[i][j]==INF)
				dis2[i][j]=1;
		}//建公路网
	floyd1();
	floyd2();
	if(dis1[1][n]==INF||dis2[1][n]==INF){
		cout<<-1<<endl;
		return 0;
	}//特判
	cout<<max(dis1[1][n],dis2[1][n])<<endl;
	return 0;//完结撒花！
}