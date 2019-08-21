#include<iostream>
using namespace std;


struct node
{
    char c;
    int left,right;
};

node tree[100000];
string s;
int sidx,cnt;

int newnode(char c){
    cnt++;
    tree[cnt].c=c;
    tree[cnt].left=tree[cnt].right=0;
    return cnt;
}

void build(int &id){
    if(sidx>=s.size()||s[sidx]=='.'){
        sidx++;
        return ;
    }
    id=newnode(s[sidx]);
    sidx++;
    build(tree[id].left);
    build(tree[id].right);
}

void inorder(int id){
    if(id==0)
        return ;
    inorder(tree[id].left);
    cout<<tree[id].c;
    inorder(tree[id].right);
}

void postorder(int id){
    if(id==0)
        return;
    postorder(tree[id].left);
    postorder(tree[id].right);
    cout<<tree[id].c;
}

int main(){
    cin>>s;
    int root;
    build(root);
    inorder(root);
    cout<<endl;
    postorder(root);
    return 0;
}