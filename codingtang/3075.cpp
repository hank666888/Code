/**
   f[i]=max(f[j])+s[i]  max(1,d-g)<=i-j<=d+g
*/
#include<iostream>
#define INF 1e9
using namespace std;

int n,d,k;
int x[500010],s[500010],f[500010];
int h,t;
int q[500010];

void push(int p){
    while(h<t&&f[q[t-1]]<=f[p])
        t--;
    q[t++]=p;
}

/**bool C(int g){
    for(int i=1;i<=n;i++){
        f[i]=-INF;
        for(int j=i-1;j>=0;j--){
            if(x[i]-x[j]<max(1,d-g))
                continue;
            if(x[i]-x[j]>d+g)
                break;
            f[i]=max(f[i],f[j]+s[i]);
            if(f[i]>=k)
                return true;
        }
    }
    return false;
}
*/

bool C(int mid){
    int p=0;
    h=0,t=0;
    f[0]=0;
    for(int i=1;i<=n;i++)
        f[i]=-INF;
    for(int i=1;i<=n;i++){
        while(p<i&&x[i]-x[p]>=max(1,d-mid))
            push(p++);
        while(x[i]-x[q[h]]>d+mid&&h<t)
            h++;
        if(h>=t||f[q[h]]==-INF)
            continue;
        else
            f[i]=f[q[h]]+s[i];
        if(f[i]>=k)
            return true;
    }
    return false;
}

int main(){
    cin>>n>>d>>k;
    for(int i=1;i<=n;i++)
        cin>>x[i]>>s[i];
    int l=0,r=INF+1;
    while(l<r){
        int mid=(r-l)/2+l;
        if(C(mid))
            r=mid;
        else
            l=mid+1;
    }
    if(l==INF+1)
        cout<<-1<<endl;
    else
        cout<<l<<endl;
    return 0;
}
