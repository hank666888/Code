#include<iostream>
using namespace std;

int n,m;
char a[10000010];

void work(char c){
    if(c=='+'){
        int x;
        for(int i=n;i>=1;i--){
            if(a[i]=='0'){
                x=i;
                a[i]='1';
                break;
            }
        }
        for(int i=x+1;i<=n;i++)
            a[i]='0';
    }
    else if(c=='-'){
        int x;
        for(int i=n;i>=1;i--){
            if(a[i]=='1'){
                x=i;
                a[i]='0';
                break;
            }
        }
        for(int i=x+1;i<=n;i++)
            a[i]='1';
    }
    else if(c=='*'){
        n++;
        a[n]='0';
    }
    else{
        n--;
    }
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++){
        char c;
        cin>>c;
        work(c);
    }
    for(int i=1;i<=n;i++)
        cout<<a[i];
    cout<<endl;
    return 0;
}
