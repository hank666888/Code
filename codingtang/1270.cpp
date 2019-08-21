#include<iostream>
using namespace std;

int n,m;
int G[110][110];
int ans;
int debug[110];
int G2[110][110];

int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        G[x][y]=1;
        G2[y][x]=1;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i!=j&&j!=k&&i!=k&&G[i][k]&&G[k][j]){
                    G[i][j]=1;
                    G2[j][i]=1;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        int a=0,b=0;
        for(int j=1;j<=n;j++){
            if(G[i][j])
                a++;
            else if(G2[i][j])
                b++;
        }
        if(a>=(n+1)/2||b>=(n+1)/2)
            ans++;
    }
    cout<<ans<<endl;
    return 0;
}