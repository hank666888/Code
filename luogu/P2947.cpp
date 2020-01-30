#include <iostream>
#include <stack>
using namespace std;

int n, h[100010], f[100010];
stack<int> s;

int main() {
	cin >> n;
	for (int i=1; i<=n; i++) cin >> h[i];
	for (int i=n; i>=1; i--) {
		while (!s.empty() && h[i] >= h[s.top()]) 
			s.pop();
		if (s.empty()) f[i] = 0;
		else f[i] = s.top();
		s.push(i);
	}
	for (int i=1; i<=n; i++) cout << f[i] << endl;
	return 0;
}