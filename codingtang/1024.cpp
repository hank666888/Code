#include <iostream>
#include <queue>
using namespace std;

const int maxn=10010;

struct node{
    int f,num;
    bool operator < (node x) const{
        return f<x.f;
    }
}a[maxn];

int n,h,i,j,k,d[maxn],t[maxn],ans;

priority_queue<node> pq;

int main(){
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>a[i].f;
        a[i].num=i;
    }
    for(i=1;i<=n;i++)
        cin>>d[i];
    for(i=1;i<n;i++)
        cin>>t[i];
    cin>>h;
    for(i=1;i<=n;i++){       
        h-=t[i-1];            
        int now=0;
        while(!pq.empty())     
            pq.pop();
        for(j=1;j<=i;j++)    
            pq.push(a[j]);
        for(j=1;j<=h;j++){
            node s;
            s=pq.top();       
            if(s.f>0)         
                now+=s.f;   
            s.f-=d[s.num];   
            pq.pop();        
            pq.push(s);        
        }
        ans=max(ans,now);    
    }
    cout<<ans<<endl;
    return 0;
} 