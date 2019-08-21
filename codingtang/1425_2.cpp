#include<iostream>
using namespace std;

const int dir[8][2]={{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1}};
int n,m;
char a[110][110];

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]=='*'){
                cout<<'*';
                continue;
            }
            int count=0;
            for(int k=0;k<8;k++){
                int nx=i+dir[k][0],ny=j+dir[k][1];
                if(a[nx][ny]=='*')
                    count++;
            }
            cout<<count;
        }
        cout<<endl;
    }
    return 0;
}
