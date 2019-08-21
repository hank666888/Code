#include<cstdio>
#include<cstring>
char a[1000],b[1000];
int n,s=1;
struct node
{
	int l,r;
}t[260];

void dfs(int q,int w,int o)
{
	if(s==n+1) return;
	for(int i=q;i<=w;i++)
		if(b[i]==a[s]){
			if(!t[o].l) t[o].l=b[i];
			else t[o].r=b[i];
			s++;
			dfs(q,i-1,b[i]);
			dfs(i+1,w,b[i]);
		}
}
void hdfs(int a){
	if(a){
		hdfs(t[a].l);
		hdfs(t[a].r);
		printf("%c",a);
	}
}
int main(){
	scanf("%s%s",a+1,b+1);
	n=strlen(a+1);
	dfs(1,n,0);
	hdfs(a[1]);
}