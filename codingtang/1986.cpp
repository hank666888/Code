#include<iostream>
#include<stack>
using namespace std;

stack<long long> s;
int work[2010],cnt;
int work2[2010];

void memset(){
	while(!s.empty())
		s.pop();
}

bool check_size(){
	if(s.size()<2)
		return true;
	return false;
}

bool check_top(){
	if(s.top()>1000000000||s.top()<-1000000000)
		return true;
	return false;
}

bool judge(){
	for(int i=1;i<=cnt;i++){
		int k;
		if(work[i]==1)
			s.push(work2[i]);
		else if(work[i]==2){
			if(s.empty())
				return false;
			s.pop();
		}
		else if(work[i]==3){
			if(s.empty())
				return false;
			k=s.top();
			s.pop();
			s.push(-k);
		}
		else if(work[i]==4)
			s.push(s.top());
		else if(work[i]==5){
			if(check_size())
				return false;
			k=s.top();
			s.pop();
			int k2=s.top();
			s.pop();
			s.push(k);
			s.push(k2);
		}
		else if(work[i]==6){
			if(check_size())
				return false;
			k=s.top();
			s.pop();
			k+=s.top();
			s.pop();
			s.push(k);
			if(check_top())
				return false;
		}
		else if(work[i]==7){
			if(check_size())
				return false;
			k=s.top();
			s.pop();
			k=s.top()-k;
			s.pop();
			s.push(k);
			if(check_top())
				return false;
		}
		else if(work[i]==8){
			if(check_size())
				return false;
			k=s.top();
			s.pop();
			k*=s.top();
			s.pop();
			s.push(k);
			if(check_top())
				return false;
		}
		else if(work[i]==9){
			if(check_size())
				return false;
			k=s.top();
			s.pop();
			k=s.top()/k;
			s.pop();
			s.push(k);
			if(check_top())
				return false;
		}
		else{
			if(check_size())
				return false;
			k=s.top();
			s.pop();
			k=s.top()%k;
			s.pop();
			s.push(k);
		}
	}
	if(s.size()!=1)
		return false;
	return true; 
}

string str;

int main(){
	while(cin>>str,str!="END"){
		if(str=="NUM"){
			int x;
			cin>>x;
			work[++cnt]=1;
			work2[cnt]=x;
		}
		else if(str=="POP")
			work[++cnt]=2;
		else if(str=="INV")
			work[++cnt]=3;
		else if(str=="DUP")
			work[++cnt]=4;
		else if(str=="SWP")
			work[++cnt]=5;
		else if(str=="ADD")
			work[++cnt]=6;
		else if(str=="SUB") 
			work[++cnt]=7;
		else if(str=="MUL")
			work[++cnt]=8;
		else if(str=="DIV")
			work[++cnt]=9;
		else
			work[++cnt]=10;
	}
	int n,x;
	cin>>n;
	while(n--){
		cin>>x;
		s.push(x);
		if(!judge())
			cout<<"ERROR!\n";
		else
			cout<<s.top()<<endl;
		memset();
	}
	return 0;
}
