#include<iostream>
#include<cstring>
using namespace std;
int n,len,a[1001];
int main(){
    cin>>n;
    int i=1;
    while(1){
        memset(a,0,sizeof(a));
        int digit=0,y=i;
        while(y!=0){
            a[++digit]=y%10;
            y/=10;
        }
        if(len+digit<n) 
            len+=digit;
        else{
            int x=len+digit-n+1;
            cout<<a[x]<<endl;
            return 0;
        }
        i++;
    }
    return 0;
}