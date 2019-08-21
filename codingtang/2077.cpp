#include<iostream>
#include<queue>
using namespace std;

struct E{
    int step;
    int floor;
};

int n,a[210];

queue<E> q;

bool vis[210];

int bfs(int start,int over){
    if(start==over)
        return 0;
    E p;
    p.step=0;
    p.floor=start;
    q.push(p);
    while(!q.empty()){
        E now=q.front();
        q.pop();
        int now_floor=a[now.floor];
        now.floor+=now_floor;
        if(now.floor==over){
            return now.step+1;
        }
        if(!vis[now.floor]&&now.floor<=n){
            now.step++;
            q.push(now);
            vis[now.floor]=true;
            now.step--;
        }
        now.floor-=2*now_floor;
        if(now.floor==over)
            return now.step+1;
        if(!vis[now.floor]&&now.floor>0){
            now.step++;
            q.push(now);
            vis[now.floor]=true;
        }
    }
    return -1;
}

int main(){
    int s,o;
    cin>>n>>s>>o;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    cout<<bfs(s,o)<<endl;
    return 0;
}
