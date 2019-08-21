#include <iostream>
using namespace std;

int pa[200010],n,m;

int find(int x){
	return pa[x]==x?x:pa[x]=find(pa[x]);
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		pa[i]=i;
	for(int i=1;i<=m;i++){
		int z,x,y;
		cin>>z>>x>>y;
		if(z==1){
			pa[find(x)]=find(y);
		}
		else{
			if(find(x)==find(y))
				cout<<"Y\n";
			else
				cout<<"N\n";
		}
	}
	return 0;
}