#include <iostream>
#include <set>
#include <string>
using namespace std;

set<string> s;

int n;

int main(){
	cin>>n;
	while(n--){
		string str;
		cin>>str;
		string new_str="";
		for(int i=0;i<str.size();i++){
			if(str[i]=='/'){
				s.insert(new_str);
			}
			new_str+=str[i];
		}
		s.insert(new_str);
		cout<<s.size()-1<<endl;
	}
	return 0;
}