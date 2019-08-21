#include<iostream>
using namespace std;

int a[100010],n;
int ans;

int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=2;i<=n;i++)
        if(a[i]>a[i-1])
            ans+=a[i]-a[i-1];
    cout<<ans+a[1]<<endl;
    return 0;
}