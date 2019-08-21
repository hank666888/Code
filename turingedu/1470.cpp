#include <iostream>
#include <algorithm>
using namespace std;

struct classroom{
	int id,peo;
};

bool cmp(classroom a,classroom b){
	if(a.peo!=b.peo)
		return a.peo>b.peo;
	return a.id<b.id;
}

classroom a[1010];

int n,m;

int main(){
	cin>>m;
	for(int i=1;i<=m;i++){
		int x;
		cin>>x;
		bool flag=false;
		for(int j=1;j<=n;j++){
			if(a[j].id==x){
				flag=true;
				a[j].peo++;
				break;
			}
		}
		if(!flag){
			n++;
			a[n].id=x;
			a[n].peo=1;
		}
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n-1;i++)
		cout<<a[i].id<<"->";
	cout<<a[n].id<<endl;
	return 0;
}