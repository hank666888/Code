#include<iostream>
using namespace std;

int a[7];

int sum=0;

int main(){
    for(int i=1;i<=6;i++)
        cin>>a[i],sum+=a[i];
    if(sum%2==1){
        cout<<"no\n";
        return 0;
    }
    for(int i=1;i<=4;i++)
        for(int j=i+1;j<=5;j++)
            for(int k=j+1;k<=6;k++){
                if(a[i]+a[j]+a[k]==sum/2){
                    cout<<"yes\n";
                    return 0;
                }
            }
    cout<<"no\n";
    return 0;
}