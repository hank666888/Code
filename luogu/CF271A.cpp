#include<iostream>
using namespace std;

int n;

bool is_year(int year){
    int a=year%10,b=year/10%10,c=year/100%10,d=year/1000;
    if(a!=b&&a!=c&&a!=d&&b!=c&&b!=d&&c!=d)
        return true;
    return false;
}

int main(){
    cin>>n;
    for(int i=n+1;i<=9999;i++)
        if(is_year(i)){
            cout<<i<<endl;
            return 0;
        }
}