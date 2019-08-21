#include<iostream>
using namespace std;

int n,k;
int a[100010];

bool cut(int l){
    int cnt=0;
    for(int i=1;i<=n;i++){
        cnt+=a[i]/l;
        if(cnt>=k)
            return true;
    }
    return false;
}

int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int l=1,r=100000000+1;
    while(l<r){
        int mid=(l+r)/2;
        if(cut(mid))
            l=mid+1;
        else
            r=mid;
    }
    cout<<l-1<<endl;
    return 0;
}
