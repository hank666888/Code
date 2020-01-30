#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstring>
#define _for(i, a, b) for (int i=(a); i<=(b); i++)
#define _rep(i, a, b) for (int i=(a); i<(b); i++)
using namespace std;

const int MAXN = 2010, INF = 1e9;

struct edge {
	int to, cost;
};
std::vector<edge> G[MAXN];
void addedge(int u, int v, int c) {
	if (c >= 0) {
		G[u].push_back((edge){v, c});
		G[v].push_back((edge){u, c});
	}
	else G[u].push_back((edge){v, c});
}

int t, n, m, d[MAXN], cnt[MAXN];
bool exist[MAXN];

void clear() {
	for (int i=1; i<=n; i++) G[i].clear();
}

bool spfa(int s) {
	fill(d+1, d+1+n, INF);
	memset(exist, false, sizeof(exist));
	memset(cnt, 0, sizeof(cnt));
	queue<int> q;
	d[s] = 0;
	q.push(s);
	exist[s] = true;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		exist[v] = false;
		if (cnt[v] >= n) return true;
		_rep (i, 0, G[v].size()) {
			edge e = G[v][i];
			if (d[e.to] > d[v]+e.cost) {
				d[e.to] = d[v]+e.cost;
				if (!exist[e.to]) {
					q.push(e.to);
					exist[e.to] = true;
					cnt[e.to]++;
				}
			}
		}
	}
	return false;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		_for (i, 1, m) {
			int u, v, c;
			scanf("%d%d%d", &u, &v, &c);
			addedge(u, v, c);
		}
		if (spfa(1)) printf("YE5\n");
		else printf("N0\n");
		clear();
	}
	return 0;
}