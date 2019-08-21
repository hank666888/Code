#include<iostream>
#include<cstdio>
using namespace std;

int way;
long long x,y;
bool flag;

long long change(string str){
    long long ans=0;
    for(int i=0;i<str.size();i++)
        ans*=10,ans+=str[i]-'0';
    return ans;
}

int get_way_left(){
    if(way==0)
        return 3;
    return way-1;
}

int get_way_right(){
    if(way==3)
        return 0;
    return way+1;
}

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        string str;
        cin>>str;
        if(str=="left"){
            way=get_way_left();
        }
        else if(str=="right"){
            way=get_way_right();
        }
        else{
            long long go;
            go=change(str);
            flag=true;
            if(way==0)
                y+=go;
            if(way==1)
                x+=go;
            if(way==2)
                y-=go;
            if(way==3)
                x-=go;
            printf("(%d,%d)\n",x,y);
        }
    }
    if(!flag)
        cout<<"(0,0)\n";
    return 0;
}