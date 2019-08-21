#include <iostream>
using namespace std;

int n,m,a[51],cnt,sum;

bool flag[10010];

int main(){
	cin>>m>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		flag[a[i]]=true;
	}
	for(int i=n*m;i>=1;i--){
		if(flag[i])
			cnt==0?sum++:d--;
		else
			d++;
	}
	cout<<sum<<endl;
	return 0;
}