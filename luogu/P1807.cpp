#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#define _for(i, a, b) for (int i=(a); i<=(b); i++)
#define _rep(i, a, b) for (int i=(a); i<(b); i++)
using namespace std;

const int MAXN = 1010;

int G[MAXN][MAXN];

void addedge(int u, int v, int c) {
	G[u][v] = max(G[u][v], c);
}

int n, m, d[MAXN];
bool exist[MAXN];
queue<int> q;

void init() {
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			G[i][j] = -1;
}

void spfa(int s) {
	fill(d+1, d+1+n, -1);
	d[s] = 0;
	exist[s] = true;
	q.push(s);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		exist[v] = false;
		_for (i, 1, n) {
			if (G[v][i] != -1 && d[i] < d[v]+G[v][i]) {
				d[i] = d[v]+G[v][i];
				if (!exist[i]) {
					exist[i] = true;
					q.push(i);
				}
			}
		}
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
	spfa(1);
	cout << d[n] << endl;
	return 0;
}
