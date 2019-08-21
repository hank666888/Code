#include<iostream>
using namespace std;

int u,v,n;
int V;
int f[1010];
int t[10010],a[10010],c[10010];

void ly(int m,int b){
    for(int i=V;i>=m;i--)
        f[i]=max(f[i],f[i-m]+b);
}

void wq(int m,int b){
    for(int i=m;i<=V;i++)
        f[i]=max(f[i],f[i-m]+b);
}

void dc(int m,int b,int c){
    int k=1;
    while(k<c){
        ly(k*m,k*b);
        c-=k;
        k*=2;
    }
    ly(c*m,c*b);
}

int main(){
    cin>>u>>v>>n;
    V=v-u;
    for(int i=1;i<=n;i++)
        cin>>t[i]>>a[i]>>c[i];
    for(int i=1;i<=n;i++){
        if(t[i]*c[i]>=V)
            wq(t[i],a[i]);
        else
            dc(t[i],a[i],c[i]);
    }
    cout<<f[V]<<endl;
    return 0;
}
