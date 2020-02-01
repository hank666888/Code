#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define _for(i, a, b) for (int i=(a); i<=(b); i++)
#define _rep(i, a, b) for (int i=(a); i<(b); i++)
using namespace std;

typedef long long LL;
const int MAXM = 21, MAXN = 110, INF = 1e9;

struct edge {
	int to, cost;
};
std::vector<edge> G[MAXM];
void addedge(int u, int v, int c) {
	G[u].push_back((edge){v, c});
	G[v].push_back((edge){u, c});
}

int n, m, k, e, t, d[MAXM];
LL cost[MAXN][MAXN], f[MAXN];
bool can_t[MAXM][MAXN], exist[MAXM], used[MAXM];

int spfa(int l, int r) {
	memset(used, false, sizeof(used));
	memset(exist, false, sizeof(exist));
	fill(d+1, d+1+m, INF);
	_for (i, 1, m)
		_for (j, l, r)
			if (can_t[i][j]) used[i] = true;
	queue<int> q;
	q.push(1);
	d[1] = 0;
	exist[1] = true;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		exist[v] = false;
		if (used[v]) continue;
		_rep (i, 0, G[v].size()) {
			edge e = G[v][i];
			if (d[e.to] > d[v]+e.cost) {
				d[e.to] = d[v]+e.cost;
				if (!exist[e.to]) {
					q.push(e.to);
					exist[e.to] = true;
				}
			}
		}
	}
	return d[m];
}

int main() {
	cin >> n >> m >> k >> e;
	_for (i, 1, e) {
		int u, v, c;
		cin >> u >> v >> c;
		addedge(u, v, c);
	}
	cin >> t;
	_for (i, 1, t) {
		int p, a, b;
		cin >> p >> a >> b;
		_for (j, a, b) can_t[p][j] = true;
	}
	_for (i, 1, n)
		_for (j, 1, n)
			cost[i][j] = spfa(i, j);
	_for (i, 1, n) {
		f[i] = (LL)i*cost[1][i];
		_for (j, 1, i) 
			f[i] = min(f[i], (LL)(f[j] + k + (LL)cost[j+1][i]*(i-j)));
	}
	cout << f[n] << endl;
	return 0;
}