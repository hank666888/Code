#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string,string> par;

string find(string s){
	if(par[s]==s)
		return s;
	return par[s]=find(par[s]);
}

int main(){
	string fa,son,s;
	while(true){
		cin>>s;
		if(s[0]=='$')
			break;
		if(s[0]=='#'){
			fa=s.substr(1);
			string tmp=find(fa);
			if(tmp==""){
				par[fa]=fa;
			}
			else
				fa=tmp;
		}
		else if(s[0]=='+'){
			son=s.substr(1);
			par[son]=fa;
		}
		else{
			string tmp=s.substr(1);
			cout<<tmp<<" "<<find(tmp)<<endl;
		}
	}
	return 0;
}