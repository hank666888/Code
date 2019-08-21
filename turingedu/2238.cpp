#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct thing{
	double w,c;
};
thing a[10010];

double x,ans;

int n;
double s[110],s2[110];

void dfs(double we,double sum,int step){
	if(step>n){
		if(we<=x)
			ans=max(ans,sum);
		return ;
	}
	if(we>x)
		return ;
	if(s[n]-s[step-1]+we<=x){
		ans=max(ans,s2[n]-s2[step-1]+sum);
		return ;
	}
	dfs(we,sum,step+1);
	dfs(we+a[step].w,sum+a[step].c,step+1);
}

int main(){
	cin>>x>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].w>>a[i].c;
		s[i]=s[i-1]+a[i].w;
		s2[i]=s2[i-1]+a[i].c;
	}
	dfs(0,0,1);
	printf("%.2f\n", ans);
	return 0;
}