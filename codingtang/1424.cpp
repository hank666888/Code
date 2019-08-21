#include<iostream>
using namespace std;

int main(){
    ///crt表示第i天增加的金币数,j表示crt这个金币数已经发了多少天了
    int k,j=1,crt=1,ans=0;
    cin>>k;
    for(int i=1;i<=k;i++){
        ans+=crt;
        if(j==crt){
            crt++;
            j=1;
        }
        else
            j++;
    }
    cout<<ans<<endl;
    return 0;
}
