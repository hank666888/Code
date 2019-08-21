#include<iostream>
#include<queue>
using namespace std;

struct data{
    int x,count;
};

int n,a,b;
int k[210];
queue<data> q;
bool visited[210];

int bfs(){
    q.push((data){a,0});
    visited[a]=true;
    while(!q.empty()){
        data d=q.front();
        q.pop();
        if(d.x==b)
            return d.count;
        int down=d.x-k[d.x];
        if(down>=1&&!visited[down]){
            visited[down]=true;
            q.push((data){down,d.count+1});
        }
        int up=d.x+k[d.x];
        if(up<=n&&!visited[up]){
            visited[up]=true;
            q.push((data){up,d.count+1});
        }
    }
    return -1;
}

int main(){
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++)
        cin>>k[i];
    cout<<bfs()<<endl;
    return 0;
}
