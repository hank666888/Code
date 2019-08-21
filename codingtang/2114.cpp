#include<iostream>
using namespace std;

string s1,s2;

void calc(int l1,int r1,int l2,int r2){
    int i,j;
    for(i=l2;i<=r2;i++){
        bool flag=false;
        for(j=l1;j<=r1;j++){
            if(s2[i]==s1[j]){
                cout<<s2[i];
                flag=true;
                break;
            }
        }
        if(flag)
            break;
    }
    if(j>l1)
        calc(l1,j-1,l2,r2);
    if(j<r1)
        calc(j+1,r1,l2,r2);
}

int main(){
    cin>>s1>>s2;
    calc(0,s1.size()-1,0,s2.size()-1);
    return 0;
}