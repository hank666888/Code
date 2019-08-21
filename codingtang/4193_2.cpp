#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAXN = 1000000, INF = 1e9, mod = 100003;
typedef pair<int,int> P;

int n, m, d[MAXN], ans[MAXN];
std::vector<int> G[MAXN];
priority_queue<P, vector<P>, greater<P> > q;

void dijkstra(int s) {
	fill(d + 1, d + 1 + n, INF);
	d[s] = 0;
	q.push(P(0, s));
	ans[s] = 1;
	while (!q.empty()) {
		P p = q.top();
		q.pop();
		int v = p.second;
		if (p.first > d[v]) continue;
		for (int i = 0; i < G[v].size(); i++) {
			int to = G[v][i];
			if (d[to] > d[v] + 1) {
				d[to] = d[v] + 1;
				q.push(P(d[to], to));
				ans[to] = ans[v] % mod;
			}
			else if (d[to] == d[v] + 1) {
				ans[to] = (ans[v] + ans[to]) % mod;
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dijkstra(1);
	for (int i = 1; i <= n; i++)
		cout << ans[i] << endl;
	return 0;
}