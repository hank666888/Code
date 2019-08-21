#include <iostream>
#include <queue>
using namespace std;

struct node
{
	int idx,count;
	bool operator < (const node &a) const {
		return count<a.count;
	}
};

int ans,n,t,walk_time,rest_time,a[110],b[110],c[110];

int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	for(int i=2;i<=n;i++)
		cin>>c[i];
	cin>>t;
	for(int i=1;i<=n;i++){
		walk_time+=c[i];
		rest_time=t-walk_time;
		priority_queue<node> q;
		for(int j=1;j<=i;j++){
			q.push((node){j,a[j]});
		}
		int crt=0;
		for(int j=1;j<=rest_time;j++){
			if(q.empty())
				break;
			node x=q.top();
			crt+=x.count;
			q.pop();
			if(x.count>=b[x.idx]){
				x.count-=b[x.idx];
				q.push(x);
			}
		}
		ans=max(ans,crt);
	}
	cout<<ans<<endl;
	return 0;
}