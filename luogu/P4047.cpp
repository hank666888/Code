#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

const int MAXN = 1010;

struct edge {
	int u, v;
	double c;
};
edge es[MAXN * MAXN];
bool cmp(edge a, edge b) {
	return a.c < b.c;
}

struct point{
	int x, y;
};
point p[MAXN];

int n, cnt, f[MAXN], k;

double dist(point a, point b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
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
	sort(es+1, es+1+cnt, cmp);
	int tot = 0;
	for (int i=1; i<=cnt; i++) {
		edge e = es[i];
		if (!same(e.u, e.v)) {
			tot++;
			unite(e.u, e.v);
		}
		if (tot == n-k+1) return e.c;
	}
}

int main() {
	cin >> n >> k;
	init();
	for (int i=1; i<=n; i++) cin >> p[i].x >> p[i].y;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++) {
			if (i == j) continue;
			double tmp = dist(p[i], p[j]);
			es[++cnt].u = i;
			es[cnt].v = j;
			es[cnt].c = tmp;  
		}
	printf("%.2lf\n", kruskal());
	return 0;
}