#include<iostream>
using namespace std;

int main(){
    ///crt��ʾ��i�����ӵĽ����,j��ʾcrt���������Ѿ����˶�������
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
