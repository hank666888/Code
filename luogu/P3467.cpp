#include <iostream>
#include <stack>
using namespace std;

const int MAXN = 250010;

int n, d[MAXN], w[MAXN], num;
stack<int> s;

int main() {
	cin >> n;
	for (int i=1; i<=n; i++) cin >> d[i] >> w[i];
	for (int i=1; i<=n; i++) {
		while (!s.empty() && w[i]<=s.top()) {
			if (w[i] == s.top()) num++;
			s.pop();
		}
		s.push(w[i]);
	}
	cout << n-num << endl;
	return 0;
}