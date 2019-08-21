#include<iostream>
#include<string>
using namespace std;

struct node
{
    char c;
    int left,right,len;
};

node tree[100000];
string s1,s2;
int cnt;

int newnode(char c){
    cnt++;
    tree[cnt].c=c;
    tree[cnt].left=tree[cnt].right=0;
    tree[cnt].len=1;
    return cnt;
}

int search(int l1,int r1,int l2,int r2){
    if(l1>r1||l2>r2)
        return 0;
    int m=s2.find(s1[l1]);
    int id=newnode(s1[l1]);
    int l_id=search(l1+1,l1+m-l2,l2,m-1);
    int r_id=search(l1+m-l2+1,r1,m+1,r2);
    tree[id].left=l_id;
    tree[id].right=r_id;
    if(l_id||r_id)
        tree[id].len=tree[l_id].len+tree[r_id].len;
    return id;
}

void printxx(int root){
    if(root==0)
        return ;
    for(int i=1;i<=tree[root].len;i++)
        cout<<tree[root].c;
    cout<<endl;
    printxx(tree[root].left);
    printxx(tree[root].right);
}

int main(){
    cin>>s1>>s2;
    int root=search(0,s1.size()-1,0,s2.size()-1);
    printxx(root);
    return 0;
}
