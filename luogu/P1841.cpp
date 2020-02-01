#include <iostream>
#define _for(i, a, b) for (int i=(a); i<=(b); i++)
#define _rep(i, a, b) for (int i=(a); i<(b); i++)
using namespace std;

const int MAXN = 210, INF = 1e9;

int n, m, dis[MAXN][MAXN], num[MAXN][MAXN];
bool flag, vis[MAXN];

void init() {
	_for (i, 1, n)
		_for (j, 1, n) 
			dis[i][j] = INF;
}

void addedge(int u, int v, int c) {
	dis[u][v] = dis[v][u] = c;
	num[u][v] = num[v][u] = 1;
}

void floyd() {
	_for (k, 1, n)
		_for (i, 1, n)
			_for (j, 1, n) {
				if (dis[i][j] > dis[i][k]+dis[k][j]) {
					dis[i][j] = dis[i][k]+dis[k][j];
					num[i][j] = num[i][k]*num[k][j];
				}
				else if (dis[i][j] == dis[i][k]+dis[k][j])
					num[i][j] += num[i][k]*num[k][j];
			}
}

int main() {
	cin >> n >> m;
	init();
	_for (i, 1, m) {
		int u, v, c;
		cin >> u >> v >> c;
		addedge(u, v, c);
	}
	floyd();
	_for (i, 1, n) dis[i][i] = INF, num[i][i] = 0;
	_for (k, 1, n)
		_for (i, 1, n)
			_for (j, 1, n) {
				if (dis[i][j] == dis[i][k]+dis[k][j] && num[i][j] == num[i][k]*num[k][j] && !vis[k]) {
					cout << k << " ";
					vis[k] = true;
					flag = true;
				}
			}
	if (!flag) cout << "No important cities.";
	cout << endl;
	return 0;
}