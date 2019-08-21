#include<iostream>
using namespace std;

int n,m;

bool phi[10000010];

void prime(){
    for(int i=2;i<=n;i++){
        if(!phi[i]){
            for(int j=i*i;j<=n;j+=i)
                phi[j]=true;
        }
    }
}

int main(){
    cin>>n>>m;
    prime();
    phi[1]=phi[0]=true;
    while(m--){
        int x;
        cin>>x;
        if(phi[x])
            cout<<"No"<<endl;
        else
            cout<<"Yes"<<endl;
    }
    return 0;
}