#include<iostream>
using namespace std;

int n,x,a[30010],s[30010],ans;

int main(){
    cin>>n>>x;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++)
            if(s[j]-s[i-1]>=x){
                i=j;
                ans++;
                break;
            }
    }
    cout<<ans<<endl;
    return 0;
}