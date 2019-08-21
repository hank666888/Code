#include<iostream>
using namespace std;
struct tree{
    int parent;
    int tc,rc;
    tree(){   
        parent=tc=rc=0;
    }
}a[27];
void pre(int root){
    if(root!=0){
        cout<<char(root-1+'a');
        pre(a[root].tc);
        pre(a[root].rc);
    }
}
int main(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        char ch1;cin>>ch1;
        char ch2;cin>>ch2;
        char ch3;cin>>ch3;
        if(ch2!='0'){
            a[ch2-'a'+1].parent=ch1-'a'+1;
            a[ch1-'a'+1].tc=ch2-'a'+1;
        }
        if(ch3!='0'){
            a[ch3-'a'+1].parent=ch1-'a'+1;
            a[ch1-'a'+1].rc=ch3-'a'+1;
        }
    }
    int root;
    for(int i=1;i<=n;i++)
        if(a[i].parent==0){
            root=i;
            break;
        }
    pre(root);
    cout<<endl;
    return 0;
}