#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

typedef pair<int, int> P;
const int MAXN = 1e5+10;
const long long INF = 1e13; 

struct edge {
	int to, cost;
};
std::vector<edge> G[MAXN];

int n, m, last[MAXN];
long long d[MAXN];
priority_queue<P, vector<P>, greater<P> > q;

void dijkstra(int s) {
	fill(d+1, d+1+n, INF);
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
				last[e.to] = v;
			}
 		}
	}
}

void print(int k) {
	if (last[k] == 0) 
		return ;
	print(last[k]);
	cout << last[k] << " ";
}

int main() {
	cin >> n >> m;
	for (int i=1; i<=m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		G[u].push_back((edge){v, c});
		G[v].push_back((edge){u, c});
	}
	dijkstra(1);
	if (d[n] == INF) {
		cout << -1 << endl;
		return 0;
	}
	print(n);
	cout << n << endl;
	return 0;
}