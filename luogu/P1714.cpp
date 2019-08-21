#include <iostream>
using namespace std;

int sum[1000010],n,a[1000010],k,ans;

int m;

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){  
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    
    cout<<ans<<endl;
    return 0;
}