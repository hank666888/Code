#include<iostream>
#include<algorithm>
using namespace std;

int v[20010],c[20010];

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    for(int i=1;i<=m;i++)
        cin>>c[i];
    sort(v+1,v+1+n);
    sort(c+1,c+1+m);
    int cur=1;
    int ans=0;
    for(int i=1;i<=m;i++){
        if(c[i]>=v[cur]){
            ans+=c[i];
            cur++;
        }
        if(cur>n)
            break;
    }
    if(cur<=n)
        cout<<"you died!\n";
    else
        cout<<ans<<endl;
    return 0;
}
