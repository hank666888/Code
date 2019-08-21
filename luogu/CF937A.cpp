#include<iostream>
#include<set>
using namespace std;

set<int> s;
int ans;
int n,a[110];

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]&&!s.count(a[i])){
            ans++;
            s.insert(a[i]);
        }
    }
    cout<<ans<<endl;
    return 0;
}