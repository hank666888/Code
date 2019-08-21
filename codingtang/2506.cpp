#include<iostream>
using namespace std;

int n,m,a,b;
int p[110][110];

int main(){
    cin>>n>>m>>a>>b;
    a++,b++;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>p[i][j];
    cout<<p[a][b]<<endl;
    return 0;
}
