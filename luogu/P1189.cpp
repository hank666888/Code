#include<iostream>
using namespace std;
char map[51][51];
int dir[1010][3];
int n,m;
int p;
bool cango[51][51];
void dfs(int x,int y,int t)
{
    if(t==p)
    {
        cango[x][y]=true;
        if(x+dir[p][1]>0&&x+dir[p][1]<=n&&y+dir[p][2]>0&&y+dir[p][2]<=n&&map[x+dir[p][1]][y+dir[p][2]]!='X')
            dfs(x+dir[p][1],y+dir[p][2],t);
        return ;
    }
    else
    {
        if(x+dir[t+1][1]>0&&x+dir[t+1][1]<=n&&y+dir[t+1][2]>0&&y+dir[t+1][2]<=n&&map[x+dir[t+1][1]][y+dir[t+1][2]]!='X')
                dfs(x+dir[t+1][1],y+dir[t+1][2],t+1);
        if(x+dir[t][1]>0&&x+dir[t][1]<=n&&y+dir[t][2]>0&&y+dir[t][2]<=n&&map[x+dir[t][1]][y+dir[t][2]]!='X')
                dfs(x+dir[t][1],y+dir[t][2],t);
    }
}
int main()
{
    int fx,fy;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>map[i][j];
            if(map[i][j]=='*')
            {
                fx=i;
                fy=j;
            }
        }
    }
    cin>>p;
    for(int i=1;i<=p;i++)
    {
        string str;
        cin>>str;
        if(str=="NORTH")
        {
            dir[i][1]=-1;
            dir[i][2]=0;
        }
        else if(str=="SOUTH")
        {
            dir[i][1]=1;
            dir[i][2]=0;
        }
        else if(str=="WEST")
        {
            dir[i][1]=0;
            dir[i][2]=-1;
        }
        else
        {
            dir[i][1]=0;
            dir[i][2]=1;
        }
    }
    dfs(fx,fy,1);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(cango[i][j])
                cout<<"*";
            else if(map[i][j]=='X')
                cout<<map[i][j];
            else
                cout<<".";
        }
        cout<<endl;
    }
    return 0;
}