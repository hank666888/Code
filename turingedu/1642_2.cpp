#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

const int INF = 1e9;

struct edge {
	int to, cost;
};
std::vector<edge> G[110];

int n, m, d[110];
bool exist[110];
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
			if (d[e.to] > d[v]+e.cost) {
				d[e.to] = d[v]+e.cost;
				if (!exist[e.to]) {
					q.push(e.to);
					exist[e.to] = true;
				}
			}
		}
	}
}

int main() {
	cin >> n >> m;
	while (m--) {
		int q;
		cin >> q;
		if (q == 0) {
			int u, v;
			cin >> u >> v;
			spfa(u);
			if (d[v] == INF)
				cout << -1 << endl;
			else
				cout << d[v] << endl;
		}
		else {
			int u, v, c;
			cin >> u >> v >> c;
			G[u].push_back(edge{v, c});
			G[v].push_back(edge{u, c});
		}
	}
	return 0;
}