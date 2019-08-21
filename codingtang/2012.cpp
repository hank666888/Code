#include <cstdio>
#include <queue>
using namespace std;

struct node{
    int x,y,c;
    bool operator<(const node &p)const{
        if(p.c==c)
            return p.x<x;
        return p.c<c;
    }
};

priority_queue<node> que;

int cnt=0;

struct part{
    int x,y;
}partner[100005];

int n,a[200005];

bool vis[200005];

char c[200005];

int abs(int a){
    if(a<0)
        return -a;
    return a;
}

int main(){
    scanf("%d",&n);
    scanf("%s",&c);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        node t;
        if(i>1)
        if(c[i-1]!=c[i-2]){
            t.x=i-1;
            t.y=i;
            t.c=abs(a[i]-a[i-1]);
            que.push(t);
        }    
    }
    bool flag;
    while(!que.empty()){
        flag=0;
        node t=que.top();
        que.pop();
        if(vis[t.x]||vis[t.y])
            continue;
        partner[++cnt].x=t.x;
        vis[t.x]=true;
        partner[cnt].y=t.y;
        vis[t.y]=true;
        while(vis[t.x-1]){
            if(t.x<=2)
            {
                flag=1;
                break;
            }
            t.x--;
        }
        if(flag==1)
            continue;
        while(vis[t.y+1]){
            if(t.y>=n-1){
                flag=1;
                break;
            }
            t.y++;
        }
        if(flag==1)
            continue;
        if(c[t.x-2]!=c[t.y]&&t.x>1&&t.y<n){
            t.x=t.x-1;
            t.y=t.y+1;
            t.c=abs(a[t.x]-a[t.y]);
            que.push(t);
        }    
    }
    printf("%d\n",cnt);
    for(int i=1;i<=cnt;i++)
        printf("%d %d\n",partner[i].x,partner[i].y);
    return 0;
}