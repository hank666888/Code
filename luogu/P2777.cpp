#include<iostream>
#include<algorithm>
using namespace std;

int n;
int p[300010];
int a[300010];

int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>p[i];
    sort(p+1,p+1+n);
    for(int i=1;i<=n;i++)
        a[i]=p[i]+n-i+1;
    int maxp=0;
    for(int i=1;i<=n;i++)
        maxp=max(maxp,a[i]);
    int ans=0;
    for(int i=n;i>=1;i--){
        if(p[i]+n>=maxp)
            ans++;
        else
            break;
    }
    cout<<ans<<endl;
    return 0;
}
