#include <iostream>
using namespace std;

const long long MAXN = 210, INF = 1e14;

long long n, m, k, q, G[MAXN][MAXN], ans, res1, res2;

void init() {
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++){
			if (i == j) continue;
			G[i][j] = INF;
		}
}

void floyd() {
	for (int k=1; k<=n; k++)
		for (int i=1; i<=n; i++)
			for (int j=1; j<=n; j++)
				G[i][j] = min(G[i][j], G[i][k]+G[k][j]);
}

int main() {
	cin >> n >> m >> k >> q;
	init();
	for (int i=1; i<=m; i++) {
		long long u, v, c;
		cin >> u >> v >> c;
		G[u][v] = min(G[u][v], c);
	} 
	floyd();
	while (q--) {
		ans = INF;
		int s, t;
		cin >> s >> t;
		for (int i=1; i<=k; i++)
			ans = min(ans, G[s][i]+G[i][t]);
		if (ans != INF) {
			res1 ++;
			res2 += ans; 
		}
	}
	cout << res1 << endl << res2 << endl;
	return 0;
}