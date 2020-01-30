#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int MAXN = 1010;

struct point {
	int x, y;
};
point p[MAXN];
double dist(point a, point b) {
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int n, m, d[MAXN], G[MAXN][MAXN];
double l;

void dijkstra(int s) {
	
}

int main() {
	cin >> n >> m;
	cin >> l;
	for (int i=1; i<=n; i++) cin >> p[i].x >> p[i].y;
	for (int i=1; i<=n; i++) 
		for (int j=i+1; j<=n; j++) {
			if (dist(p[i], p[j]) < l) {
				G[i][j] = G[j][i] = dist(p[i], p[j]);
			}
		}
	for (int i=1; i<=m; i++) {
		int u, v;
		cin >> u >> v;
		G[u][v] = G[v][u] = 0;
	}

}