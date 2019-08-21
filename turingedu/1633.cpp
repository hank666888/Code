#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

char yy[5]={'a','e','i','o','u'};

string str;

char ch[110];
bool used[110];
int l,c;

bool have_yy(char x){
	for(int i=0;i<5;i++)
		if(x==yy[i])
			return true;
	return false;
}

void dfs(string str,int t){
    if(str.size()==l){
    	bool flag=false;
    	int cnt=0;
        for(int i=0;i<str.size();i++){
            if(!flag&&have_yy(str[i]))
            	flag=true;
            if(!have_yy(str[i]))
            	cnt++;
        }
        if(flag&&cnt>=2)
        	cout<<str<<endl;
        return ;
    }
    for(int i=t+1;i<=c;i++){
        if(!used[i]){
            used[i]=true;
            dfs(str+ch[i],i);
            used[i]=false;
        }
    }

}

int main(){
	cin>>l>>c;
	for(int i=1;i<=c;i++)
		cin>>ch[i];
	sort(ch+1,ch+1+c);
	dfs(str,0);
    return 0;
}