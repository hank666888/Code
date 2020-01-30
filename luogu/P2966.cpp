#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

const int MAXN = 260, INF = 200000000;

int n, m, G[MAXN][MAXN], c[MAXN], ans[MAXN][MAXN], d[MAXN], q;
bool used[MAXN];

void init() {
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++) G[i][j] = INF, ans[i][j] = INF;
}

void dijkstra(int Max) {
	fill(d+1, d+1+n, INF);
	memset(used, false, sizeof(used));
	d[Max] = 0;
	while (true) {
		int v = -1;
		for (int u=1; u<=n; u++)
			if (!used[u] && (v == -1 || d[u] < d[v]) && c[u] <= c[Max])
				v = u;
		if (v == -1) break;
		used[v] = true;
		for (int u=1; u<=n; u++)
			if (d[u] > d[v] + G[v][u] && c[u] <= c[Max]) d[u] = d[v] + G[v][u]; 
	}
}

void solve() {
	for (int i=1; i<=n; i++) {
		dijkstra(i);
		for (int j=1; j<=n; j++)
			for (int k=1; k<=n; k++)
				ans[j][k] = min(ans[j][k], d[k] + d[j] + c[i]);
	}
}

int main() {
	cin >> n >> m >> q;
	init();
	for (int i=1; i<=n; i++) cin >> c[i];
	for (int i=1; i<=m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		G[u][v] = G[v][u] = min(G[u][v], c);
	}
	solve();
	while (q--) {
		int x, y;
		cin >> x >> y;
		cout << ans[x][y] << endl;
	}
	return 0;
}