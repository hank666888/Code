#include<iostream>
#include<string>
using namespace std;

string s1,s2;

struct node{
    char c;
    int left,right;
};

void build(int l1,int r1,int l2,int r2){
    if(l1>r1||l2>r2)
        return ;
    int m=s1.find(s2[r2]);
    cout<<s1[m]<<endl;
    build(l1,m-1,l2,l2+m-1);
    build(m+1,r1,l2+m+1,r2-1);
}

int main(){
    cin>>s1>>s2;
    build(0,s1.size()-1,0,s2.size()-1);
    cout<<endl;
    return 0;
}