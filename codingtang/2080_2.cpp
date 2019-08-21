#include<iostream>
#include<queue>
using namespace std;

int G[110][110];
bool visited[110];
queue<int> q;
int n,k;

int bfs(int x){
    int count=1;
    visited[x]=true;
    q.push(x);
    while(!q.empty()){
        int now=q.front();
        q.pop();
        for(int i=1;i<=n;i++){
            if(G[now][i]&&!visited[i]){
                visited[i]=true;
                q.push(i);
                count++;
            }
        }
    }
    return count;
}

int main(){
    int ans=0,maxcount=0;
    cin>>n>>k;
    for(int i=1;i<=k;i++){
        int x,y;
        cin>>x>>y;
        G[x][y]=G[y][x]=1;
    }
    for(int i=1;i<=n;i++)
        if(!visited[i]){
            int count=bfs(i);
            if(count>maxcount)
                maxcount=count;
            ans++;
        }
    cout<<ans<<" "<<maxcount<<endl;
}
