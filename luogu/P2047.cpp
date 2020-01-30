#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN = 110, INF = 1e9;

int n, m, dis[MAXN][MAXN];
double sum[MAXN][MAXN];

void init() {
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++) dis[i][j] = INF;
}

void floyd() {
	for (int k=1; k<=n; k++) 
		for (int i=1; i<=n; i++)
			for (int j=1; j<=n; j++) 
				if (i != j && j != k && i != k) {
					if (dis[i][j] == dis[i][k] + dis[k][j])
						sum[i][j] += sum[i][k] * sum[k][j];
					if (dis[i][j] > dis[i][k] + dis[k][j]) {
						dis[i][j] = dis[i][k] + dis[k][j];
						sum[i][j] = sum[i][k] * sum[k][j];
					}
				}
}

void solve() {
	floyd();
	for (int k=1; k<=n; k++) {
		double ans = 0;
		for (int i=1; i<=n; i++) 
			for (int j=1; j<=n; j++) {
				if (i != j && j != k && i != k && dis[i][j] == dis[i][k] + dis[k][j])
					ans += (sum[i][k] * sum[k][j]) / sum[i][j];
			}
		printf("%.3f\n", ans);
	}
}

int main() {
	cin >> n >> m;
	init();
	for (int i=1; i<=m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		dis[u][v] = dis[v][u] = c;
		sum[u][v] = sum[v][u] = 1;
	}
	solve();
	return 0;
}

