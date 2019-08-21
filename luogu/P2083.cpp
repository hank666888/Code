#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+10,maxm=1e2+10;

bool vis[maxn][maxm]; 
int n,m,v,_x,_y;
struct rec{
    int cnt;
    pair<int,int> p;
};

bool operator < (const rec &a,const rec &b){
    return a.cnt>b.cnt;
}

int flr[maxn][maxm],num[maxn][maxm];

inline pair<int,int> get_Next(const pair<int,int> &p){ 
    int x=p.first,y=p.second;
    return make_pair(flr[x][y],num[x][y]);
}

priority_queue<rec>q;

int BFS(){
    for(int i=1;i<=m;++i){
        q.push((rec){0,make_pair(1,i)});
    }
    while(!q.empty()){
        rec tmp=q.top(); 
            q.pop();
        int x=tmp.p.first,y=tmp.p.second;
        if(vis[x][y]) 
            continue;
        vis[x][y]=true;
        int C=tmp.cnt;
        pair<int,int> Next=get_Next(tmp.p);
        if(tmp.p==make_pair(_x,_y)) 
            return C; 
        int del=abs(Next.first-x); 
        q.push((rec){del+C,Next});
    }
    return -1;
}

int main(){
    cin>>n>>m>>v>>_x>>_y;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j){
            int a,b; 
            scanf("%d%d",&a,&b);
            flr[i][j]=a,num[i][j]=b;
        }
    int ans=BFS();
    if(ans==-1) 
        puts("impossible");
    else 
        cout<<ans*v;
    return 0;
}