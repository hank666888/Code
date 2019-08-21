#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

const long long INF = 1e13, MAXN = 1000010;
typedef pair<long long, long long> P;

struct edge {
	long long to, cost;
};
vector<edge> G[MAXN], rG[MAXN];

long long d[MAXN], n, m, ans;
priority_queue< P, vector<P>, greater<P> > q;

void dijkstra1(long long s) {
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
			if (d[e.to] > d[v]+e.cost) {
				d[e.to] = d[v]+e.cost;
				q.push(P(d[e.to], e.to));
			}
		}
	}
}

void dijkstra2(long long s) {
	fill(d+1, d+1+n, INF);
	d[s] = 0;
	q.push(P(0, s));
	while (!q.empty()) {
		P p = q.top();
		q.pop();
		int v = p.second;
		if (p.first > d[v]) continue;
		for (int i=0; i<rG[v].size(); i++) {
			edge e = rG[v][i];
			if (d[e.to] > d[v]+e.cost) {
				d[e.to] = d[v]+e.cost;
				q.push(P(d[e.to], e.to));
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i=1; i<=m; i++) {
		long long u, v, c;
		cin >> u >> v >> c;
		G[u].push_back(edge{v, c});
		rG[v].push_back(edge{u, c});
	}
	dijkstra1(1);
	for (int i=2; i<=n; i++)
		ans += d[i];
	dijkstra2(1);
	for (int i=2; i<=n; i++)
		ans += d[i];
	cout << ans << endl;
	return 0;
}	