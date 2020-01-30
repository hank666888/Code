#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;

const int MAXN = 1010;

struct point {
	int x, y;
};
point p[MAXN];
double dist(point a, point b) {
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

struct edge {
	int u, v;
	double c;
};
edge es[MAXN*MAXN];
bool cmp(edge a, edge b) {
	return a.c < b.c;
}

int n, cnt, f[MAXN];
double ans;

void init() {
	for (int i=1; i<=n; i++) f[i] = i;
}

int find(int x) {
	if (f[x] != x) f[x] = find(f[x]);
	return f[x];
}

void unite(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return ;
	f[x] = y;
}

bool same(int x, int y) {
	return find(x) == find(y);
}

void kruskal() {
	int num = 0;
	sort(es+1, es+1+cnt, cmp);
	for (int i=1; i<=cnt; i++) {
		if (!same(es[i].u, es[i].v))  {
			ans = es[i].c;
			unite(es[i].u, es[i].v);
			if (++num == n-1) break;
		}
	}
}

int main() {
	cin >> n;
	init();
	for (int i=1; i<=n; i++) cin >> p[i].x >> p[i].y;
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			if (i == j) continue;
			es[++cnt].u = i;
			es[cnt].v = j;
			es[cnt].c = dist(p[i], p[j]);
		}
	}
	kruskal();
	printf("%.0lf\n", ans*ans);
	return 0;
}