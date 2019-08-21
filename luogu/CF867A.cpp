#include<iostream>
#include<string>
using namespace std;

string s;

int main()
{
    int n;
    cin>>n;
    cin>>s;
    if(n!=1&&s[0]=='S'&&s[n-1]=='F')
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}