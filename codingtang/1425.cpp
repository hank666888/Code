#include<iostream>
using namespace std;
const int maxn=110,maxm=110;

int n,m;
char landmine[maxn][maxm];
int ans[maxn][maxm];
int dir[8][2]={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};

bool check(int x,int y){
    if(x>=1&&x<=n&&y>=1&&y<=m)
        return true;
    return false;
}

void count(){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(landmine[i][j]=='?'){
                for(int k=0;k<8;k++){
                    int x=i+dir[k][0],y=j+dir[k][1];
                    if(check(x,y)&&landmine[x][y]=='*')
                        ans[i][j]++;
                }
            }
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>landmine[i][j];
    count();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(landmine[i][j]=='*')
                cout<<"*";
            else
                cout<<ans[i][j];
        }
        cout<<endl;
    }
    return 0;
}
