#include <iostream>
using namespace std;

int n;

long long p[110],a[110];

bool flag,used[110];

void print(){
	for(int i=1;i<=n;i++)
		cout<<p[i]<<" ";
	cout<<endl;
}

void dfs(int t){
	if(t>n){
		print();
		flag=true;
		return ;
	}
	if(!flag)
		for(int i=1;i<=n;i++){
			if(!used[i]&&(t==1||(p[t-1]*2==a[i]||(p[t-1]%3==0&&p[t-1]/3==a[i])))){
				used[i]=true;
				p[t]=a[i];
				dfs(t+1);
				used[i]=false;
			}
		}
}	

int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dfs(1);//从一开始，便于填充
	return 0;//完结撒花！
}