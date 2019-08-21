#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 110, INF = 1e8;

int path[MAXN], cnt, d[MAXN][MAXN], G[MAXN][MAXN], n, m, ans = INF, pos[MAXN][MAXN];

void init() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i != j)
				G[i][j] = INF;
}

void get_path(int x, int y) {
	if (pos[x][y] == 0)
		return ;
	get_path(x, pos[x][y]);
	path[++cnt] = pos[x][y];
	get_path(pos[x][y], y);
}

void min_cycle() {
	memcpy(d, G, sizeof(G));
	for (int k = 1; k <= n; k++) { 
		for (int i = 1; i < k; i++) {
			for (int j = i + 1; j < k; j++) {
				if(d[i][j] + G[i][k] + G[k][j] < ans) {
					ans = d[i][j] + G[i][k] + G[k][j];
					cnt = 0;
					path[++cnt] = i;
					get_path(i, j);
					path[++cnt] = j;
					path[++cnt] = k;
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++)
				if(d[i][j] > d[i][k] + d[k][j]){
					d[i][j] = d[i][k] + d[k][j];
					pos[i][j] = k;
				}
		}
	}
}

int main() {
	cin >> n >> m;
	init();
	for (int i = 1; i <= m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		G[u][v] = G[v][u] = min(G[u][v], c);
	}
	min_cycle();
	if (ans == INF)
		cout << "No solution." << endl;
	else {
		for (int i = 1; i <= cnt; i++)
			cout << path[i] << " ";
		cout << endl;
	}
	return 0;
}