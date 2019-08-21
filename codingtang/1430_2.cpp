#include<iostream>
using namespace std;

int n,x,y;
int r,st,bc;

int rank(){
    int xt=min(x,n+1-x);
    int yt=min(y,n+1-y);
    return min(xt,yt);
}

int firstNum(int n){
    int ans=0;
    for(int i=1;i<r;i++){
        ans+=(n-1)*4;
        n-=2;
    }
    return ans+1;
}

int edge(int n){
    for(int i=1;i<r;i++)
        n-=2;
    return n;
}

int cal(){
    if(x==r)
        return st+y-r;
    if(y==n+1-r)
        return st+(bc-1)+x-r;
    if(x==n+1-r)
        return st+(bc-1)*2+n+1-r-y;
    if(y==r)
        return st+(bc-1)*3+n+1-r-x;
}

int main(){
    int ans;
    cin>>n>>x>>y;
    r=rank();
    st=firstNum(n);
    bc=edge(n);
    ans=cal();
    cout<<ans<<endl;
    return 0;
}