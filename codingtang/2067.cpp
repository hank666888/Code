#include<iostream>
#include<stack>
#include<string>
using namespace std;

stack<int> s;
string str;
bool judge(){
	for(int i=0;i<str.size();i++){
		if(str[i]=='(')
			s.push(1);
		else if(str[i]=='[')
			s.push(2);
		else if(str[i]==')'){
			if(s.empty())
				return false;
			if(s.top()==2)
				return false;
			s.pop();
		}
		else{
			if(s.empty())
				return false;
			if(s.top()==1)
				return false;
			s.pop();
		}
	} 
	if(s.empty()) 
		return true;
	return false;
}

int main(){
	cin>>str;
	if(judge())
		cout<<"OK"<<endl;
	else
		cout<<"Wrong"<<endl;
	return 0;
} 
