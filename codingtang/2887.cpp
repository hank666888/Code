#include<iostream>
#include<algorithm>
using namespace std;

int n,a[1010];

int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    int ans=-1;
    int i=1,j=n;
    while(i<j){
        ans=max(ans,a[i]+a[j]);
        i++;
        j--;
    }
    cout<<ans<<endl;
    return 0;
}
