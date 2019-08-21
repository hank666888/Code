#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

int n,m;
int G[1010][1010];
int a[1010],b[1010],d[1010],c[1010];

int dfs(int t){
    if(d[t]>0)
        return d[t];
    for(int i=1;i<=n;i++){
        if(G[t][i]){
            int tmp=dfs(i);
            if(tmp>d[t])
                d[t]=tmp;
        }
    }
    d[t]+=1;
    return d[t];
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int s;
        scanf("%d",&s);
        memset(b,0,sizeof(b));
        for(int j=1;j<=s;j++){
            scanf("%d",&a[j]);
            b[a[j]]++;
        }
        int o=0;
        for(int k=a[1];k<=a[s];k++)
            if(!b[k])
                c[++o]=k;
        for(int j=1;j<=s;j++)
            for(int k=1;k<=o;k++)
                G[a[j]][c[k]]=1;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        if(dfs(i)>ans)
            ans=dfs(i);
    cout<<ans<<endl;
    return 0;
}