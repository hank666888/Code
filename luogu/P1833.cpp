#include<iostream>
using namespace std;

int th,tm,bh,bm;
int n;
int t[10010],c[10010],p[10010];
int m;
int f[1010];

void ly(int w,int v){
    for(int i=m;i>=w;i--)
        f[i]=max(f[i],f[i-w]+v);
}

void wq(int w,int v){
    for(int i=w;i<=m;i++)
        f[i]=max(f[i],f[i-w]+v);
}

void dc(int w,int v,int h){
    int k=1;
    while(k<h){
        ly(k*w,k*v);
        h-=k;
        k*=2;
    }
    ly(h*w,h*v);
}

int main(){
    char c1,c2;
    cin>>th>>c1>>tm;
    int t1=th*60+tm;
    cin>>bh>>c2>>bm;
    int t2=bh*60+bm;
    m=t2-t1;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>t[i]>>c[i]>>p[i];
    for(int i=1;i<=n;i++){
        if(p[i]==0)
            wq(t[i],c[i]);
        else{
            if(t[i]*p[i]>=m)
                wq(t[i],c[i]);
            else
                dc(t[i],c[i],p[i]);
        }
    }
    cout<<f[m]<<endl;
    return 0;
}
