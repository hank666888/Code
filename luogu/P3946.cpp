#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAXN = 100010, INF = 1e9;

struct edge { 
	int to, cost;
};
std::vector<edge> G[MAXN];

int n, m, s, t, g, x, h[MAXN], l[MAXN], d[MAXN];
bool exist[MAXN];
queue<int> q;

void spfa(int s) {
	fill(d+1, d+1+n, INF);
	memset(exist, false, sizeof(exist));
	d[s] = 0;
	q.push(s);
	exist[s] = true;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		exist[v] = false;
		for (int i=0; i<G[v].size(); i++) {
			edge e = G[v][i];
			if (d[e.to] > d[v] + e.cost) {
				d[e.to] = d[v] + e.cost;
				if (!exist[e.to] && h[e.to] + d[e.to] * x <=l[e.to]) {
					exist[e.to] = true;
					q.push(e.to);
				}
			}
		}
	}
}

int main() {
	cin >> n >> m >> s >> t >> g >> x;
	for (int i=1; i<=n; i++) cin >> h[i] >> l[i];
	for (int i=1; i<=m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		G[u].push_back((edge){v, c});
		G[v].push_back((edge){u, c});
	}
	spfa(s);
	if (d[t] <= g) cout << d[t] <<endl ;
	else cout << "wtnap wa kotori no oyatsu desu!" << endl;
	return 0;
}