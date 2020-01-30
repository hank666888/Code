#include <iostream>
#include <stack>
using namespace std;

int n, a[3000010], f[3000010];
stack<int> s;

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i=1; i<=n; i++) cin >> a[i];
	for (int i=n; i>=1; i--) {
		while (!s.empty() && a[i] >= a[s.top()]) s.pop();
		if (s.empty()) f[i] = 0;
		else f[i] = s.top();
		s.push(i);
	}
	for (int i=1; i<=n; i++) cout << f[i] << " ";
	cout << endl;
	return 0;
}