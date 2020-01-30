#include <iostream>
#include <queue>
#include <vector>
#define _for(i, a, b) for(int i=(a); i<=(b); i++)
using namespace std;

typedef pair<int, int> P;
const int MAXN = 230;

struct edge {
	int to, cost;
};
std::vector<edge> G[MAXN];
void addedge(int u, int v, int c) {
	G[u].push_back((edge){v, c});
}

int n, m, f, x, st, d[MAXN], cnt[MAXN];
priority_queue<P> q;
bool exist[MAXN];

int spfa(int s) {
	d[s] = x;
	cnt[s] = 1;
	exist[s] = true;
	q.push(P(x, s));
	while (!q.empty()) {
		P p = q.top();
		q.pop();
		exist[p.second] = false;
		cnt[p.second]++;
		if (cnt[p.second] > n) return -1;
		if (G[p.second].size() == 0) continue;
		_for(i, 0, G[p.second].size()-1) {
			//cout << 1;
			edge e = G[p.second][i];
			if (d[p.second]+e.cost > d[e.to]) {
				d[e.to] = d[p.second]+e.cost;
				if (!exist[e.to]) {
					exist[e.to] = true;
					q.push(P(-d[e.to], e.to));
				}
			}
		}
	}
	int ans = 0;
	_for(i, 1, n) ans = max(ans,d[i]);
	return ans;
}

int main() {
	cin >> x >> m >> n >> f >> st;
	_for(i, 1, m) {
		int u, v;
		cin >> u >> v;
		addedge(u, v, x);
	}
	_for(i, 1, f) {
		int u, v, w;
		cin >> u >> v >> w;
		addedge(u, v, x-w);
	}
	cout  << spfa(st) << endl;
	return 0;
}