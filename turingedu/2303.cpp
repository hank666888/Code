#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1000001;
inline int read(){
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,l,r,ans,maxx;
int a[N];
inline bool pd(int lim){
    int cur=1;
    while(cur<=n){
        int pos=lower_bound(a+cur,a+n+1,a[cur-1]+lim)-a;
        if(a[pos]!=a[cur-1]+lim) return false;
        cur=pos+1;
    }
    return true;
}
int main(){
    n=read();
    for(int i=1;i<=n;++i){
        a[i]=read(); maxx=max(maxx,a[i]);
        a[i]+=a[i-1];
    }
    for(int i=1;i<=n;++i){
        if(a[n]%a[i]!=0||a[i]<maxx) continue;
        if(pd(a[i])){ans=a[i]; break;}
    }
    printf("%d\n",ans);
    return 0;
}