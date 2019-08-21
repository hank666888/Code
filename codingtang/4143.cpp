#include <iostream>
#include <cstring>
using namespace std;

string A, B;
int f[1010][1010], m, n;

int main() {
	while (cin >> A >> B) {
		m = A.size(), n = B.size();
		A = ' ' + A, B = ' ' + B;
		for (int i=1; i<=m; i++)
			for (int j=1; j<=n; j++)
				if (A[i] == B[j])
					f[i][j] = f[i-1][j-1]+1;
				else
					f[i][j] = max(f[i-1][j], f[i][j-1]);
		cout << f[m][n] << endl;
		memset(f, 0, sizeof(f));
 	}
 	return 0;
}