#include <cstdio>
#include <deque>
using namespace std;

struct data
{
	int v,id;
};

int n,m;

int ans[2000010];

int a[2000010];

deque<data> dq;

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	ans[1]=0;
	for(int i=2;i<=n;i++){
		while(!dq.empty()&&dq.back().v>=a[i-1])
			dq.pop_back();
		dq.push_back((data){a[i-1],i-1});
		while(dq.front().id<i-m)
			dq.pop_front();
		ans[i]=dq.front().v;
	}
	for(int i=1;i<=n;i++)
		printf("%d\n",ans[i]);
	return 0;
}