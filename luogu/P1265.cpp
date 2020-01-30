#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 5010, INF = 1e9;

struct point {
	double x, y;	
};
point p[MAXN];

int n;
double mincost[MAXN];
bool used[MAXN];

double dist(point a, point b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double prim() {
	memset(used, false, sizeof(used));
	fill(mincost+1, mincost+1+n, INF);
	double ret = 0;
	mincost[1] = 0;
	while(true) {
		int v = -1;
		for (int u=1; u<=n; u++)
			if (!used[u] && (v == -1 || mincost[u] < mincost[v])) v = u;
		if (v == -1) break;
		used[v] = true;
		ret += mincost[v];
		for (int u=1; u<=n; u++)
			if (mincost[u] > dist(p[v], p[u]) && !used[u]) mincost[u] = dist(p[v], p[u]);
	}
	return ret;	
}

int main() {
	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> p[i].x >> p[i].y;
	printf("%.2f\n", prim());
	return 0;
}