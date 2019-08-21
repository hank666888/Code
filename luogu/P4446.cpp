#include <iostream>
#define N 32000
using namespace std;

bool flag[N+20];
int prime[N+20]={1,1};
int prime_num;

int main(){
	for(int i=2;i<=N;i++){
		if(!flag[i])
			prime[++prime_num]=i;
		for(int j=1;j<=prime_num&&prime[j]*i<=N;j++){
			flag[prime[j]*i]=1;
			if(i%prime[j]==0)
				break;
		}
	}
	int n;
	cin>>n;
	while(n--){
		long long x;
		cin>>x;
		long long ans=1;
		for(int i=1;i<=prime_num&&x>=prime[i]*prime[i]*prime[i];i++){
			int cnt=0;
			while(x%prime[i]==0){
				cnt++;
				x/=prime[i];
			}
			while(cnt>=3){
				ans*=prime[i];
				cnt-=3;
			}
		}
		long long l=1,r=1000000;
		while(l<r){
			long long mid=(l+r+1)/2;
			if(mid*mid*mid<=x)
				l=mid;
			else
				r=mid-1;
		}
		cout<<(l*l*l==x?ans*l:ans)<<endl;
	}
	return 0;
}