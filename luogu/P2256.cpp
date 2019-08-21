#include <iostream>
using namespace std;

int fa[1000010];

string str[1000010];//用字符串数组存便于查找字符串下标

int n,m,k;

int init(){
	for(int i=1;i<=n;i++)
		fa[i]=i;
}//并查集初始化（注意一定要初始化！否则等于白打）

int findname(string s){
	for(int i=1;i<=n;i++)
		if(s==str[i])
			return i;
}//查找字符串下标

int find(int x){
	if(fa[x]!=x)
		fa[x]=find(fa[x]);
	return fa[x];
}//带路径压缩的“查”

void unite(int x,int y){
	x=find(x),y=find(y);
	if(x==y)
		return ;
	fa[x]=y;
}//基于“查”上面的“并”

bool same(int x,int y){
	return find(x)==find(y);
}//判断两个字符串的下标（及两个字符串）是否在同一集合内

int main(){
	cin>>n>>m;
	init();//初始化
	for(int i=1;i<=n;i++)
		cin>>str[i];
	for(int i=1;i<=m;i++){
		string s1,s2;
		cin>>s1>>s2;
		int x=findname(s1),y=findname(s2);
		unite(x,y);
	}//读入+合并
	cin>>k;
	while(k--){
		string s1,s2;
		cin>>s1>>s2;
		int x=findname(s1),y=findname(s2);
		if(same(x,y))
			cout<<"Yes.\n";
		else
			cout<<"No.\n";
	}//询问在线搞
	return 0;//完结撒花！
}