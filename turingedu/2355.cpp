#include<iostream>
using namespace std;

int n,x,a[100010],ans;

long long s[100010];

int main(){
    cin>>n>>x;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(s[j]-s[i-1]>x){
                ans++;
                i=j-1;
                break;
            }
        }
    }
    cout<<ans+1<<endl;
    return 0;
}