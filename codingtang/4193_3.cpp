#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> P;

const int MAXN = 1000010;
const int INF = 1e9;

int n, m, ans[MAXN], d[MAXN];
vector<int> G[MAXN];
priority_queue< P, vector<P>, greater<P> > q;

void dijkstra(int s) {
	fill(d + 1, d + 1 + n, INF);
	q.push(P(0, s));
	ans[s] = 1;
	d[s] = 0;
	while (!q.empty()) {
		P p = q.top();
		q.pop();
		int v = p.second;
		if (p.first > d[v])
			continue;
		for (int i = 0; i < G[v].size(); i++) {
			int e = G[v][i];
			if (d[v] + 1 < d[e]) {
				d[e] = d[v] + 1;
				ans[e] = ans[v] % 100003;
				q.push(P(d[e], e));
			}
			else if (d[v] + 1 == d[e]) {
				ans[e] = (ans[e] + ans[v]) % 100003;
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dijkstra(1);
	for (int i = 1; i <= n; i++)
		cout << ans[i] << endl;
	return 0;
}