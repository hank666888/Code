#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;

int n;
string s[30];

int my_pre(char ch)
{
	if(ch=='<')
        return 1;
	if(ch=='(')
        return 2;
	if(ch=='[')
        return 3;
	if(ch=='{')
        return 4;
	return 5;
}

bool my_judge(string s)
{
	stack<int> a;
	int k;
	for(int i=0;i<s.size();i++)
	{
		k=my_pre(s[i]);
		if(k<5)
		{
			if(a.empty())
			{
				a.push(k);
				continue;
			}
			else
			{
				if(k>a.top())
                    return false;
				else
				{
					a.push(k);
					continue;
				}
			}
		}
		if(k==5)
		{

			if(a.empty())
                return false;
			if(s[i]=='>')
			{
				if(a.top()==1)a.pop();
				else return false;
			}
			if(s[i]==')')
			{
				if(a.top()==2)
                    a.pop();
				else
                    return false;
			}
			if(s[i]==']')
			{
				if(a.top()==3)
                    a.pop();
				else
                    return false;
			}
			if(s[i]=='}')
			{
				if(a.top()==4)
                    a.pop();
				else
                    return false;
			}

		}
	}
	if(a.empty())
        return true;
	else return false;
}

void init()
{
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>s[i];
		if(my_judge(s[i]))
            cout<<"YES"<<endl;
		else
            cout<<"NO"<<endl;
	}
}

int main()
{
	init();
	return 0;
}
