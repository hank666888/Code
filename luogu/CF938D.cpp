#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

typedef pair<int, int> P;
const int MAXN = 2 * (1e5 + 1) + 10;
const long long INF = 1e18;

struct edge {
	long long to, cost;
};
std::vector<edge> G[MAXN];

int n, m;
long long d[MAXN];
priority_queue< P, vector<P>, greater<P> > q;

void dijkstra(int s) {
	fill(d+1, d+2+n, INF);
	d[s] = 0;
	q.push(P(0, s));
	while (!q.empty()) {
		P p = q.top();
		q.pop();
		int v = p.second;
		if (d[v] < p.first) continue;
		for (int i=0; i<G[v].size(); i++) {
			edge e = G[v][i];
			if (d[e.to] > d[v] + e.cost) {
				d[e.to] = d[v] + e.cost;
				q.push(P(d[e.to], e.to));
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i=1; i<=m; i++) {
		int u, v;
		long long c;
		cin >> u >> v >> c;
		G[u].push_back((edge){v, 2*c});
		G[v].push_back((edge){u, 2*c});
	}
	for (int i=1; i<=n; i++) {
		long long x;
		cin >> x;
		G[n+1].push_back((edge){i, x});
	}
	dijkstra(n+1);
	for (int i=1; i<=n; i++) cout << d[i] << " ";
	return 0;
}