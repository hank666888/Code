#include<iostream>
using namespace std;

int n,k;
int a[510];
int f[510];

int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    f[1]=1;
    for(int i=2;i<=n;i++)
        f[i]=max(f[i-1],a[i]);
}