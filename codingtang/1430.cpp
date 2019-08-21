#include<iostream>
using namespace std;
int juzhen(int n,int x,int y){
    if(x==1)
        return y;
    else if(y==n)
        return x+n-1;
    else if(x==n)
        return (2*n-1)+(n-y);
    else if(y==1)
        return (3*n-2)+(n-x);
    else
        return juzhen(n-2,x-1,y-1)+4*(n-1);
}
int main(){
    int x,y,n;
    cin>>n>>x>>y;
    cout<<juzhen(n,x,y);
}
