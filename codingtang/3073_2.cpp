#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int n,q,a[1010];

bool cmp(int c,int d,int x){
    for(int i=1;i<=c;i++){
        if(d%10!=x%10)
            return false;
        d/=10;
        x/=10;
    }
    return true;
}

bool cmp1(int c,int d,int x){
    return x%int(pow(10,c))==d;
}

int main(){
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=q;i++){
        int c,d;
        bool flag=false;
        cin>>c>>d;
        for(int j=1;j<=n;j++){
            if(cmp(c,d,a[j])){
                cout<<a[j]<<endl;
                flag=true;
                break;
            }
        }
        if(!flag)
            cout<<-1<<endl;
    }
    return 0;
}
