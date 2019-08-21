#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

const int MAXN=200000;

struct peo
{
	int l,r,w;
	bool operator > (const peo& p) const {
		if(w==p.w)
			return l>p.l;
		return w>p.w;
	}
};

int n,tot,m[MAXN+10];
char s[MAXN+10];
bool b[MAXN+10];
priority_queue<peo,vector<peo>,greater<peo> > q;
peo ans[MAXN+10];

void push(int x,int y){
	q.push((peo){x,y,abs(m[x]-m[y])});
}

int main(){
	cin>>n>>s+1;
	for(int i=1;i<=n;i++){
		cin>>m[i];
	}
	for(int i=1;i<n;i++){
		if(s[i]!=s[i+1])
			push(i,i+1);
	}
	while(!q.empty()){
		peo now=q.top();
		q.pop();
		if(b[now.l]||b[now.r])
			continue;
		ans[++tot]=now;
		b[now.l]=b[now.r]=true;
		int l=now.l-1,r=now.r-1;
		while(l>=1&b[l])
			l--;
		while(r<=n&&b[r])
			r++;
		if(l<1||r>n)
			continue;
		if(s[l]!=s[r])
			push(l,r);
	}
	cout<<tot<<endl;
	for(int i=1;i<=tot;i++)
		cout<<ans[i].l<<" "<<ans[i].r<<endl;
	return 0;
}