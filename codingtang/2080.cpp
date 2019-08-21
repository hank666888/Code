#include<iostream>
#include<queue>
using namespace std;

const int N=100005;

struct node{
    int v,head,nxt;
};node a[N];

queue <int> f;

int tot=0;

void add(int x,int y)
{
    tot++;
    a[tot].v=y;
    a[tot].nxt=a[x].head;
    a[x].head=tot;
}

int n,k,ans1,ans2,maxx;
bool flag[N];

void bfs(int n){
    while(!f.empty()) f.pop();
    ans1++;
    ans2=1;
    flag[n]=1;
    f.push(n);
    while(!f.empty()){
        int k=f.front();
        f.pop();
        for(int i=a[k].head;i!=0;i=a[i].nxt){
            if(!flag[a[i].v]){
                f.push(a[i].v);
                ans2++;
                flag[a[i].v]=1;
            }
        }
    }
    maxx=max(maxx,ans2);
}

int main()
{
    int x,y;
    cin>>n>>k;
    for(int i=1;i<=k;i++){
        cin>>x>>y;
        add(x,y);
        add(y,x);
    }
    for(int i=1;i<=n;i++)
      if(!flag[i])
        bfs(i);
    cout<<ans1<<" "<<maxx<<endl;
    return 0;
}
