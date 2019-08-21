#include <iostream>
using namespace std;
const int dir[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

int n, m;

int map[15][15];

int fx, fy, sx, sy;

int ans[10010][2];

bool vis[15][15];

bool flag;

bool cango(int x, int y)
{
    if (x >= 1 && x <= n && y >= 1 && y <= m && map[x][y] == 1)
        return true;
    return false;
}

void dfs(int deep, int x, int y)
{
    if (x == fx && y == fy)
    {
        flag = true;
        ans[deep][0] = x;
        ans[deep][1] = y;
        for (int i = 0; i < deep; i++)
            cout << "(" << ans[i][0] << "," << ans[i][1] << ")"
                 << "->";
        cout << "(" << ans[deep][0] << "," << ans[deep][1] << ")" << endl;
        return;
    }
    vis[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dir[i][0], ny = y + dir[i][1];
        if (cango(nx, ny) && !vis[nx][ny])
        {
            ans[deep][0] = x;
            ans[deep][1] = y;
            dfs(deep + 1, nx, ny);
        }
    }
    vis[x][y] = false;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> map[i][j];
    cin >> sx >> sy >> fx >> fy;
    dfs(0, sx, sy);
    if (!flag)
        cout << -1 << endl;
    return 0;
}