#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define _for(i, a, b) for (int i=(a); i<=(b); i++)
#define _rep(i, a, b) for (int i=(a); i<(b); i++)
using namespace std;

const int MAXN = 1010, INF = 1e9;

struct edge {
	int to, cost;
};
std::vector<edge> G[MAXN], rG[MAXN];
void addedge(int u, int v, int c) {
	G[u].push_back((edge){v, c});
	rG[v].push_back((edge){u, c});
}

int n, m, d1[MAXN], d2[MAXN], ans;
bool exist[MAXN];

void spfa1(int s) {
	memset(exist, false, sizeof(exist));
	fill(d1+1, d1+1+n, INF);
	queue<int> q;
	d1[s] = 0; 
	q.push(s);
	exist[s] = true;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		exist[v] = false;
		_rep (i, 0, G[v].size()) {
			edge e = G[v][i];
			if (d1[e.to] > d1[v]+e.cost) {
				d1[e.to] = d1[v]+e.cost;
				if (!exist[e.to]) {
					exist[e.to] = true;
					q.push(e.to);
				}
			}
		}
	}
}

void spfa2(int s) {
	memset(exist, false, sizeof(exist));
	fill(d2+1, d2+1+n, INF);
	queue<int> q;
	d2[s] = 0; 
	q.push(s);
	exist[s] = true;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		exist[v] = false;
		_rep (i, 0, rG[v].size()) {
			edge e = rG[v][i];
			if (d2[e.to] > d2[v]+e.cost) {
				d2[e.to] = d2[v]+e.cost;
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
	_for (i, 1, m) {
		int u, v, c;
		cin >> u >> v >> c;
		addedge(u, v, c);
	}
	spfa1(1);
	spfa2(1);
	_for (i, 2, n) ans += d1[i]+d2[i];
	cout << ans << endl;
	return 0;
}