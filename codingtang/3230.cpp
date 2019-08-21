#include<iostream>
using namespace std;
const int maxn=110,maxs=10010;

int n,S;
int f[maxs];
int s[maxn],c[maxn],p[maxn];

void ly(int c,int v){
    for(int j=S;j>=v;j--)
        f[j]=max(f[j],f[j-v]+c);
}

void wq(int c,int v){
    for(int j=v;j<=S;j++)
        f[j]=max(f[j],f[j-v]+c);
}

void dc(int c,int v,int p){
    int k=1;
    while(k<p){
        ly(k*c,k*v);
        p-=k;
        k*=2;
    }
    ly(p*c,p*v);
}

int main(){
    cin>>n>>S;
    for(int i=1;i<=n;i++)
        cin>>c[i]>>s[i]>>p[i];
    for(int i=1;i<=n;i++){
        if(s[i]*p[i]>S)
            wq(c[i],s[i]);
        else
            dc(c[i],s[i],p[i]);
    }
    cout<<f[S]<<endl;
    return 0;
}
