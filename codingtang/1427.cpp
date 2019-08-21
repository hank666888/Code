#include<iostream>
#include<queue>
using namespace std;

const int MAXN=100010;


struct data
{
    int idx,v;
    bool operator < (data d) const {
        return v<d.v;
    }
};

priority_queue<data> q1,q2;

int n,a[MAXN],s[MAXN],ans;

int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>s[i];
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++){
        q2.push((data){i,a[i]+2*s[i]});
    }    
    q1.push((data){0,0});
    q2.push((data){n+1,0});
    int right=0;
    for(int x=1;x<=n;x++){
        data l,r;
        while(true){
            r=q2.top();
            if(r.idx<=right)
                q2.pop();
            else
                break;
        }
        l=q1.top();
        if(l.v>=r.v-2*s[right]){
            ans+=l.v;
            q1.pop();
        }
        else{
            ans+=r.v-2*s[right];
            q2.pop();
            for(int i=right-1;i<r.idx;i++)
                q1.push((data){i,a[i]});
            right=r.idx;
        }
        cout<<ans<<endl;
    }
    return 0;
}