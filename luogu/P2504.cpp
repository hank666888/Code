#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAXN = 1010;

struct point {
	int x, y;
};
point p[MAXN];

struct edge {
	int from, to;
	double cost;
};
edge es[MAXN*MAXN];
bool cmp(edge a, edge b) {
	return a.cost < b.cost;
}

int n, m, dis[510], cnt, f[MAXN], tot;

double dist(point a, point b) {
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

void init() {
	for (int i=1; i<=n; i++) f[i] = i;
}

int find(int x) {
	if (f[x] != x) f[x] = find(f[x]);
	return f[x];
}

void unite(int x, int y) {
	x = find(x), y = find(y);
	if (x == y) return ;
	f[x] = y;
}

bool same(int x, int y) {
	return find(x) == find(y);
}

double kruskal() {
	double ret;
	sort(es+1, es+1+cnt, cmp);
	for (int i=1; i<=cnt; i++) 
		if (!same(es[i].from, es[i].to)) {
			unite(es[i].from, es[i].to);
			ret = es[i].cost;
		}
	return ret;
}

int main() {
	cin >> m;
	for (int i=1; i<=m; i++) cin >> dis[i];
	cin >> n;
	for (int i=1; i<=n; i++) cin >> p[i].x >> p[i].y;
	init();
	for (int i=1; i<=n; i++) 
		for (int j=1; j<=n; j++)
			if (i != j) {
				es[++cnt].from = i;
				es[cnt].to = j;
				es[cnt].cost = dist(p[i], p[j]);
			}
	double ans = kruskal();
	for (int i=1; i<=m; i++) 
		if (ans <= dis[i]) tot++;
	cout << tot << endl;
	return 0;
}