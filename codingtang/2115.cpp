#include<iostream>
#include<string>
using namespace std;

char tree[1<<12];
int n;
string s;

char build(int id,int l,int r){
    if(l==r){
        tree[id]=s[l]=='0'?'B':'I';
        cout<<tree[id];
        return tree[id];
    }
    int m=(l+r)/2;
    char t1=build(id*2,l,m);
    char t2=build(id*2+1,m+1,r);
    if(t1=='I'&&t2=='I')
        tree[id]='I';
    else if(t1=='B'&&t2=='B')
        tree[id]='B';
    else    
        tree[id]='F';
    cout<<tree[id];
    return tree[id];
}

int main(){
    cin>>n;
    cin>>s;
    build(1,0,s.size()-1);
    return 0;
}