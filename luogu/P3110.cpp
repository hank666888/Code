#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 100010, INF = 1e9;

struct edge {
	int to, cost;
};
std::vector<edge> G[MAXN];

int b, e, p, n, m, d1[MAXN], d2[MAXN], d3[MAXN], ans = INF;
bool exist[MAXN];
queue<int> q;

void spfa(int s, int d[]) {
	fill(d+1, d+1+n, INF);
	memset(exist, false, sizeof(exist));
	d[s] = 0;
	exist[s] = true;
	q.push(s);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		exist[v] = false;
		for (int i=0; i<G[v].size(); i++) {
			edge e = G[v][i];
			if (d[e.to] > d[v] + e.cost) {
				d[e.to] = d[v] + e.cost;
				if (!exist[e.to]) {
					q.push(e.to);
					exist[e.to] = true;
				}
			}
		}
	}
}

int main() {
	cin >> b >> e >> p >> n >> m;
	for (int i=1; i<=m; i++) {
		int u, v, c;
		cin >> u >> v;
		G[u].push_back((edge){v, 1});
		G[v].push_back((edge){u, 1});
	}
	spfa(1, d1);
	spfa(2, d2);
	spfa(n, d3);
	for (int i=1; i<=n; i++) ans = min(ans, b*d1[i] + e*d2[i] + p*d3[i]);
	cout << ans << endl;
	return 0;
}