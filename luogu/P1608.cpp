#include <iostream>
#include <cstring>
using namespace std;

const int INF = 1e9;

int G[2010][2010], n, m, ans[2010], d[2010];
bool used[2010];

void init() {
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			G[i][j] = INF;
}

void dijkstra(int s) {
	fill(d+1, d+1+n, INF);
	memset(used, false, sizeof(used));
	d[s] = 0;
	ans[s] = 1;
	while (true) {
		int v = -1;
		for (int u=1; u<=n; u++)
			if (!used[u] && (v == -1 || d[u]<d[v])) v = u;
		if (v == -1)
			break;
		used[v] = true;
		for (int u=1; u<=n; u++) {
			if (d[u] > d[v]+G[v][u]) {
				d[u] = d[v]+G[v][u];
				ans[u] = ans[v];
			}
			else if (d[u] == d[v]+G[v][u]) ans[u] += ans[v];
		}
	}
}

int main() {
	cin >> n >> m;
	init();
	for (int i=1; i<=m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		G[u][v] = min(G[u][v], c);
	}
	dijkstra(1);
	if (d[n] == INF) cout << "No answer" << endl;
	else cout << d[n] << " " << ans[n] << endl;
	return 0;
}