#include<iostream>
#include<cmath>
using namespace std;

bool is_prime(long long a){
    for(int i=2;i<=sqrt(a);i++)
        if(a%i==0)
            return false;
    return true;
}

int main(){
    long long n;
    cin>>n;
    for(int i=2;i<=sqrt(n);i++)
        if(n%i==0&&is_prime(i)&&is_prime(n/i)){
            cout<<n/i<<endl;
            return 0;
        }
}
