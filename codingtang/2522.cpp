#include<iostream>
using namespace std;

int n,m;
int a[51][21],b[51][21];

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>b[i][j];
    int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i][j]==b[i][j])
                ans++;
    cout<<ans<<endl;
    return 0;
}
