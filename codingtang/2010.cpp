#include <iostream>
#include <queue>
using namespace std;

struct f
{
	int x,a,b,c,ans;
	bool operator > (const f& x) const{
		return ans>x.ans;
	}
};

int n,m;

priority_queue< f , vector<f> , greater<f> > pq;

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int a,b,c;
		cin>>a>>b>>c;
		pq.push((f){1,a,b,c,a+b+c});
	}
	int k=1;
	while(k<=m){
		f now=pq.top();
		cout<<pq.top().ans<<" ";
		pq.pop();
		now.x++;
		now.ans=now.a*now.x*now.x+now.b*now.x+now.c;
		pq.push(now);
		k++;
	}
	cout<<endl;
	return 0;
}