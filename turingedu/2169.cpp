#include <iostream>
#include <cmath>
using namespace std;
 
int n,s,ans;
int a[21];
 
int sum(){
    int tot=0;
    for(int i=1;i<=n;i++)
        tot+=a[i];
    return tot;
}
 
void dfs(int t){
    if(t>n){
        if(sum()==s)
            ans++;
    }
    else{
        a[t]=a[t-1]-1;
        dfs(t+1);
        a[t]=a[t-1]+1;
        dfs(t+1);
    }
}
 
int main(){
    cin>>n>>s;
    dfs(2);
    cout<<ans<<endl;
    return 0;
}