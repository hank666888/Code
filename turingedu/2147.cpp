#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s[1010];
int G[1010][1010], ans, n;
bool visited[1010];

bool cmp(string a, string b) {
    return a.size() < b.size();
}

bool isqz(string a, string b) {
    for (int i = 0; i < a.size(); i++)
        if (a[i] != b[i])
            return false;
    return true;
}

void dfs(int x, int k) {
    visited[x] = true;
    //cout << s[x] << endl;
    ans = max(ans, k);
    for (int i = n; i >= 1; i--)
        if (G[x][i] && !visited[i]) {
            dfs(i, k+1);
        }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    sort(s+1, s+1+n, cmp);
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (isqz(s[i], s[j]))
                G[j][i] = 1;
        }
    }
    for (int i = n; i >= 1; i--)
        if (!visited[i])
            dfs(i, 0);
    cout << ans + 1 << endl;
    return 0;
}
