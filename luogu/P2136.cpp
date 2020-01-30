#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAXN = 1010, INF = 1e9;

struct edge {
	int to, cost;
};
std::vector<edge> G[MAXN];

int n, m, d[MAXN], cnt[MAXN], ans;
bool exist[MAXN], flag;

void spfa(int s) {
	queue<int> q;
	fill(d+1, d+1+n, INF);
	memset(exist, false, sizeof(exist));
	memset(cnt, 0, sizeof(cnt));
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
				cnt[e.to] = cnt[v]+1;
				if (cnt[e.to] > n) {
					flag = true;
					return ;
				} 
				if (!exist[e.to]) {
					exist[e.to] = true;
					q.push(e.to);
				}
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i=1; i<=m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		G[u].push_back((edge){v, -c});
	}
	spfa(1);
	ans = d[n];
	spfa(n);
	if (flag) {
		cout << "Forever love" << endl;
		return 0;
	}
	cout << min(ans, d[1]) << endl;
	return 0;
}