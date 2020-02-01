#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define _for(i, a, b) for (int i=(a); i<=(b); i++)
#define _rep(i, a, b) for (int i=(a); i<(b); i++)
using namespace std;

typedef pair<int, int> P;
const int MAXN = 50010, INF = 1e9;

struct edge {
	int to, cost;
};
std::vector<edge> G[MAXN];
void addedge(int u, int v, int c) {
	G[u].push_back((edge){v, c});
	G[v].push_back((edge){u, c});
}//建无向边操作

int n, m, rel[7], d[7][MAXN], ans = INF;//记得ans要赋INF，以及d数组要开二维
bool vis[7];

void dijkstra(int s) {
	priority_queue<P, vector<P>, greater<P> > q;
	d[s][rel[s]] = 0;
	q.push(P(0, rel[s]));
	while (!q.empty()) {
		P p = q.top();
		q.pop();
		int v = p.second;
		if (p.first > d[s][v]) continue;
		_rep (i, 0, G[v].size()) {
			edge e = G[v][i];
			if (d[s][e.to] > d[s][v]+e.cost) {
				d[s][e.to] = d[s][v]+e.cost;
				q.push(P(d[s][e.to], e.to));
			}
		}
	}
}//标准堆优化dijkstra

void dfs(int cur, int cost, int pos) {
	if (cost > ans) return ;
	if (cur == 5) {
		ans = min(ans, cost);
		return ;
	}
	_for (i, 1, 5) 
		if (!vis[i]) {
			vis[i] = true;
			dfs(cur+1, cost+d[pos][rel[i]], i);
			vis[i] = false;
		}
}//标准枚举全排列

int main() {
	cin >> n >> m;
	_for (i, 1, 5) cin >> rel[i];
	_for (i, 1, m) {
		int u, v, c;
		cin >> u >> v >> c;
		addedge(u, v, c);
	}//建图
	rel[6] = 1;
	memset(d, 0x3f, sizeof(d));//记得d数组要初始化
	_for (i, 1, 6) dijkstra(i);
	dfs(0, 0, 6);
	cout << ans << endl;
	return 0;//完结撒花
}