#include<iostream>
using namespace std;

string s1,s2;

void calc(int l1,int r1,int l2,int r2){
    if(l1>r1||l2>r2)
        return ;
    int m=s2.find(s1[l1]);
    calc(l1+1,l1+m-l2,l2,m-1);
    calc(l1+m-l2+1,r1,m+1,r2);
    cout<<s1[l1];
}

int main(){
    cin>>s1>>s2;
    calc(0,s1.size()-1,0,s2.size()-1);
    return 0;
}