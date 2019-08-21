#include<cstdio>
const int dirx[12]={1,-1,0,0,2,-2,0,0,1,-1,1,-1};
const int diry[12]={0,0,1,-1,0,0,2,-2,-1,1,1,-1};

char a[1001][1001];
int n,m,ans;

bool cango(int x,int y){
    if(x>=1&&x<=n&&y>=1&&y<=m&&a[x][y]=='#')
        return true;
}

void dfs(int x,int y){
    if(!cango(x,y)) 
        return;
    a[x][y]='-';
    for(int i=0;i<12;i++) 
        dfs(x+dirx[i],y+diry[i]);
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) 
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i][j]=='#'){
                ans++;
                dfs(i,j);
            }
    printf("%d\n",ans);
    return 0;
}