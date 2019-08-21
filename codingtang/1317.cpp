#include <iostream>
#include <map>
using namespace std;

map<string,string> fa;
char c[100010];
int id=1;
string str[100010];
int k;

string find(string x){
	if(fa[x]!=x)
		fa[x]=find(fa[x]);
	return fa[x];
}

void unite(string x,string y){
	x=find(x),y=find(y);
	if(x==y)
		return ;
	fa[x]=y;
}

int main(){
	while(cin>>c[id],c[id]!='$'){
		cin>>str[id];
		id++;
	}
	id--;
	for(int i=1;i<=id;i++)
		fa[str[i]]=str[i];
	for(int i=1;i<=id;i++){
		if(c[i]=='#'){
			k=i;
		}
		else if(c[i]=='+'){
			fa[str[i]]=str[i];
			unite(str[i],str[k]);
		}
		else{
			cout<<str[i]<<" "<<find(str[i])<<endl;
		}
	}
	return 0;
}
/*
#George
+Rodney
#Arthur
+Gareth
+Walter
#Gareth
+Edward
?Edward
?Walter
?Rodney
?Arthur
$
*/

/*
Edward Arthur
Walter Arthur
Rodney George
Arthur Arthur
*/