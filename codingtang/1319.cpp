#include<cstdio>
#include<iostream>
using namespace std;

struct node
{
    int x,y;
 
}f[350][350];
 
node find(node k)
{
    if((f[k.x][k.y].x==k.x)&&(f[k.x][k.y].y==k.y))
        return k;
    return f[k.x][k.y]=find(f[k.x][k.y]);
}
 
 
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            f[i][j].x=i;
            f[i][j].y=j;
        }
    }
    node k1,k2;
    for(int i=1;i<=m;i++){
        int x;
        int y;
        char c;
        scanf("%d%d",&x,&y);
        cin>>c;
        if(c=='D'){
            k1=find(f[x][y]);
            k2=find(f[x+1][y]);
        }
        if(c=='R'){
            k1=find(f[x][y]);
            k2=find(f[x][y+1]);
        }
        if((k1.x==k2.x)&&(k1.y==k2.y)){
            printf("%d\n",i);
            return 0;
        }
        else f[k2.x][k2.y]=k1;
    }
    printf("draw\n");
    return 0;
}
