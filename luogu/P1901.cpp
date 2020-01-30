#include <iostream>
#include <stack>
using namespace std;

const int MAXN = 1000010;

int n, h[MAXN], v[MAXN], f[MAXN], ans;
stack<int> s;

int main() {
	cin >> n;
	for (int i=1; i<=n; i++) cin >> h[i] >> v[i];
	for (int i=1; i<=n; i++) {
		while (!s.empty() && h[i] > h[s.top()]) {
			f[i] += v[s.top()];
			s.pop();
		}
		if (!s.empty()) f[s.top()] += v[i];
		s.push(i);
	}
	for (int i=1; i<=n; i++) ans = max(ans, f[i]);
	cout << ans << endl;
	return 0;
}