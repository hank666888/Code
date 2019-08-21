#include<iostream>
using namespace std;

int x[40010];
int num[15010];
int a[15010],b[15010],c[15010],d[15010];

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>x[i];
        num[x[i]]++;
    }
    for(int i=1;i*9<=n;i++){
        int xa,xb,xc,xd;
        int sum=0;
        for(xd=9*i+1;xd<=n;xd++){
            xc=xd-i;
            xa=xd-i*9-1;
            xb=xd-i*7-1;
            sum+=num[xa]*num[xb];
            c[xc]+=sum*num[xd];
            d[xd]+=sum*num[xc];
        }
        sum=0;
        for(xa=n-i*9-1;xa>=1;xa--){
            xb=xa+2*i;
            xc=xa+i*8+1;
            xd=xa+i*9+1;
            sum+=num[xc]*num[xd];
            a[xa]+=sum*num[xb];
            b[xb]+=sum*num[xa];
        }
    }
    for(int i=1;i<=m;i++)
        cout<<a[x[i]]<<" "<<b[x[i]]<<" "<<c[x[i]]<<" "<<d[x[i]]<<endl;
    return 0;
}
