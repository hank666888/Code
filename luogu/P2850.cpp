#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdio>
#define _for(i, a, b) for (int i=(a); i<=(b); i++)
#define _rep(i, a, b) for (int i=(a); i<(b); i++)
using namespace std;

const int MAXN = 510, INF = 1e9;

struct edge {
	int to, cost;
};
std::vector<edge> G[MAXN];
void addedge(int u, int v, int c) {
	G[u].push_back((edge){v, c});
}

int t, n, m, w, d[MAXN], cnt[MAXN];
bool exist[MAXN];

void clear() {
	_for (i, 1, n) G[i].clear();
}

bool spfa(int s) {
	fill(d+1, d+1+n, INF);
	memset(exist, false, sizeof(exist));
	memset(cnt, 0, sizeof(cnt));
	queue<int> q;
	d[s] = 0;
	exist[s] = true;
	q.push(s);
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
		scanf("%d%d%d", &n, &m, &w);
		_for (i, 1, m) {
			int u, v, c;
			scanf("%d%d%d", &u, &v, &c);
			addedge(u, v, c);
			addedge(v, u, c);
		}
		_for (i, 1, w) {
			int u, v, c;
			scanf("%d%d%d", &u, &v, &c);
			addedge(u, v, -c);
		}
		if (spfa(1)) printf("YES\n");
		else printf("NO\n");
		clear();
	}
	return 0;
}