#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAXN = 100010, INF = 1e9;
typedef pair<int, int> P;

struct edge {
	int to, cost;
};
std::vector<edge> G[MAXN];

int n, m, s, t1, t2, d[MAXN], ans;
priority_queue<P, vector<P>, greater<P> > q;

void dijkstra(int s) {
	fill(d+1, d+1+n, INF);
	d[s] = 0;
	q.push(P(0, s));
	while (!q.empty()) {
		P p = q.top();
		q.pop();
		int v = p.second;
		if (p.first > d[v]) continue;
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
	cin >> m >> n >> s >> t1 >> t2;
	for (int i=1; i<=m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		G[u].push_back((edge){v, c});
		G[v].push_back((edge){u, c});
	}
	dijkstra(t1);
	ans = d[s] + d[t2];
	dijkstra(t2);
	ans = min(ans, d[s] + d[t1]);
	cout << ans << endl;
	return 0;
}