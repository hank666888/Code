#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 1010;
const double INF = 1e10;

struct circle {
	double x, y, r;
};
circle c[MAXN];

double xs, ys, xt, yt, d[MAXN], G[MAXN][MAXN];
int n;
bool used[MAXN];

double dist(circle a, circle b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)) - a.r - b.r;
}

void dijkstra(int s) {
	fill(d+1, d+1+n, INF);
	memset(used, false, sizeof(used));
	d[s] = 0;
	while (true) {
		int v = -1;
		for (int u=1; u<=n; u++)
			if (!used[u] && (v == -1 || d[u] < d[v])) v = u;
		if (v == -1) break;
		used[v] = true;
		for (int u=1; u<=n; u++)
			if (d[v] + G[v][u] < d[u]) d[u] = d[v] + G[v][u];
	}
}

int main() {
	cin >> xs >> ys >> xt >> yt;
	c[1] = circle{xs, ys, 0};
	c[2] = circle{xt, yt, 0};
	cin >> n;
	for (int i=1; i<=n; i++) cin >> c[i+2].x >> c[i+2].y >> c[i+2].r;
	n += 2;
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			if (i == j) continue;
			G[i][j] = dist(c[i], c[j]);
			if (G[i][j] < 0) G[i][j] = 0;
		}
	}
	dijkstra(1);
	printf("%.10f\n", d[2]);
	return 0;
}