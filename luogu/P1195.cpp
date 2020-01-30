#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1010, MAXM = 10010;

struct edge{
	int u, v, c;	
};
edge es[MAXM];
bool cmp(edge a, edge b) {
	return a.c < b.c;
}

int n, m, k, cnt, f[MAXN];

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

void kruskal() {
	sort(es+1, es+1+cnt, cmp);
	int ret = 0, tot = 0;
	for (int i=1; i<=cnt; i++) {
		edge e = es[i];
		if (!same(e.u, e.v)) {
			unite(e.u, e.v);
			ret += e.c;
			tot++;
		}
		if (tot == n-k) {
			cout << ret << endl;
			return ;
		}
	}
	cout << "No Answer" << endl;
	return ;
}

int main() {
	cin >> n >> m >> k;
	init();
	for (int i=1; i<=m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		es[++cnt] = (edge){u, v, c};
	}
	kruskal();
	return 0;
}