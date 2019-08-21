#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct peo
{
	long long x,num;
};

bool cmp(peo a,peo b){
	return a.x<b.x;
}

long long ans1,ans2=1e13;

long long l;
int n;

peo a[100010];

long long mid,sum,ans;

int main(){
	cin>>l>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].x>>a[i].num,mid+=a[i].num;
	mid=(mid+1)/2;
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		sum+=a[i].num;
		if(sum>mid){
			mid=i;
			break;
		}
	}
	for(int i=1;i<=n;i++){
		ans+=abs(a[i].x-a[mid].x)*a[i].num;
	}
	cout<<ans<<endl;
	return 0;
}	