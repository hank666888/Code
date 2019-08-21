/*
    f[i][j]表示前i行中选择并且第i行必选的最小分数值
    f[i][j]=min(f[k][j-1]+C(k,i)+V(i))
    C(k,i)表示第k行和第i行之间的分数值
    V(i)表示第i行之间的分数值
*/
#include<iostream>
#include<cmath>
using namespace std;

const int INF=1e9;

int n,m,r,c,ans=INF;
int a[20][20],b[20],d[20][20],v[20];

int C(int x,int y){
    int ret=0;
    for(int i=1;i<=c;i++)
        ret+=abs(a[x][b[i]]-a[y][b[i]]);
    return ret;
}

int js_v(int x){
    int ret=0;
    for(int i=1;i<c;i++)
        ret+=abs(a[x][b[i]]-a[x][b[i+1]]);
    return ret;
}

void dp(){
    int tmp=INF;
    for(int i=1;i<=n;i++){
        v[i]=js_v(i);
        d[i][1]=v[i];
    }
    for(int i=2;i<=n;i++)
        for(int j=2;j<=i;j++){
            d[i][j]=INF;
            for(int k=j-1;k<=i-1;k++)
                d[i][j]=min(d[i][j],d[k][j-1]+C(k,i)+v[i]);
            if(j==r&&d[i][j]<tmp)
                tmp=d[i][r];    
        }
    if(tmp<ans)
        ans=tmp;
}

void search(int t){
    if(t>c){
        dp();
        return ;
    }
    for(int i=b[t-1]+1;i<=m;i++){
        b[t]=i;
        search(t+1);
    }
}

int main(){
    cin>>n>>m>>r>>c;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    search(1);
    cout<<ans<<endl;
    return 0;
}