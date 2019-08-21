#include<iostream>
using namespace std;

int d,t;
bool tree[1<<20];

int main(){
    int now;
    cin>>d>>t;
    for(int i=1;i<=t;i++){
        now=1;
        for(int j=1;j<=d;j++){
            tree[now]=!tree[now];
            if(tree[now])
                now*=2;
            else
                now=now*2+1;
        }
    }
    cout<<now/2<<endl;
    return 0;
}