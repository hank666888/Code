#include<iostream>
using namespace std;

int n,m;

int a[110][110];
int ans;

bool can(int x,int y,int l){
    for(int i=x;i<=x+l-1;i++)
        for(int j=y;j<=y+l-1;j++)
            if(a[i][j]==0)
                return false;
    return true;
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    for(int i=1;i<=n-ans;i++)
        for(int j=1;j<=m-ans;j++){
            if(a[i][j]==1){
                for(int k=ans+1;k<=min(n,m);k++){
                    if(i+k<=n&&j+k<=m&&can(i,j,k))
                        ans=k;
                    else
                        break;
                }
            }
        }
    cout<<ans<<endl;
}