#include <iostream>
using namespace std;

int F,maxv,cnt,path[510],G[510][510],d[510];

void find_circuit(int t){
	for(int i=1;i<=maxv;i++){
		if(G[t][i]){
			G[t][i]--;
			G[i][t]--;
			find_circuit(i);
		}
	}
	path[++cnt]=t;
}

int main(){
	cin>>F;
	for(int i=1;i<=F;i++){
		int x,y;
		cin>>x>>y;
		G[x][y]++;
		G[y][x]++;
		d[x]++,d[y]++;
		if(x>maxv)
			maxv=x;
		if(y>maxv)
			maxv=y;
	}
	int start=1;
	for(int i=1;i<=maxv;i++){
		if(d[i]%2==1){
			start=i;
			break;
		}
	}
	find_circuit(start);
	for(int i=cnt;i>=1;i--)
		cout<<path[i]<<endl;
	return 0;
}	