#include <cstdio>
#include <iostream>

using namespace std;
int p(int j){
    char c;
    while(scanf("%c",&c)!=EOF){
        if(c=='a') 
            j++;
        if(c=='(') 
            j=j+p(0);
        if(c=='|') 
            return max(j,p(0));
        if(c==')') 
            return j;
    }
    return j;
}

int main(){
    cout<<p(0);
    return 0;
}