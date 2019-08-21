#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#pragma GCC optimize(2)
using namespace std;

typedef pair<int, int> P;
const int INF = 1e9;

struct edge {
	int to, cost;
};
std::vector<edge> G[110];

struct PriorityQueue{
    int size;
    P a[100010];
};

PriorityQueue q;

void push(P p){
    int i = ++q.size;
    while (i/2) {
        if(p.first <= q.a[i/2].first)
            break;
        q.a[i] = q.a[i/2];
        i /= 2;
    }
    q.a[i] = p;
}

void pop(){
	P e = q.a[q.size];
	q.size--;
	int i = 1;
	while (i*2<=q.size) {
		int minval = i*2;
		if(i*2+1<=q.size)
			minval = q.a[minval].first < q.a[i*2+1].first ? i*2+1 : minval;
		if(q.a[minval].first <= e.first)
			break;
		q.a[i] = q.a[minval];
		i = minval;
	}
	q.a[i] = e;
}

P top() {
	return q.a[1];
}

bool empty() {
	return q.size;
}

int n, m, d[110];

void dijkstra(int s) {
	fill(d+1, d+1+n, INF);
	d[s] = 0;
	push(P(0, s));
	while (!empty()) {
		P p = top();
		pop();
		int v = p.second;
		if (p.first > d[v])	continue;
		for (int i=0; i<G[v].size(); i++) {
			edge e = G[v][i];
			if (d[e.to] > d[v]+e.cost) {
				d[e.to] = d[v]+e.cost;
				push(P(d[e.to], e.to));
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
			dijkstra(u);
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