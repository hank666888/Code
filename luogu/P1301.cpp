#include <iostream>
#include <queue>
using namespace std;

const int dir[8][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}, {1, -1}, {-1, 1}, {1, 1}, {-1, -1}};

//方向数组

struct node {
	int x, y, step, way;
};
queue<node> q;//队列定义

int n, m, map[110][110];
bool vis[110][110][110];

bool cango(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= m;
}//判断是否超出边界

void bfs() {
	node st;
	st.x = 1;
	st.y = 1;
	st.step = 0;
	st.way = 8;//初始没有方向
	q.push(st);
	while (!q.empty()) {
		node now = q.front();
		q.pop();
		if (now.x == n && now.y == m) {
			cout << now.step << endl;
			return ;
		}//如果成立，直接输出并结束
		for (int i=0; i<8; i++) {
			int nx = now.x + dir[i][0] * map[now.x][now.y], ny = now.y + dir[i][1] * map[now.x][now.y];
			if (cango(nx, ny) && i != now.way && !vis[nx][ny][i]) {
				node next;
				next.x = nx;
				next.y = ny;
				next.step = now.step + 1;
				next.way = i;
				vis[nx][ny][i] = true;
				q.push(next);
			}//判断+放入队列
		}
	}
	cout << "NEVER" << endl;
}

int main() {
	cin >> m >> n;//注意，先输入列数再输入行数
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++) cin >> map[i][j];
	bfs();
	return 0;//完结撒花！
}