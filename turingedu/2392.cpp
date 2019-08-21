#include <iostream>
#include <string>
using namespace std;

string s;
long long a, ans = 1;
int k = -1;

int main() {
    cin >> s;
    while (true) {
        a = 0;
        bool flag = false;
        for (int i = k + 1; i < s.size(); i++){
            if (s[i] == '*') {
                k = i;
                break;
            }
            if (i == s.size() - 1) {
                flag = true;
            }
            a *= 10;
            a += (int)(s[i] - '0');
        }
        ans *= a;
        if (flag)
            break;
    }
    cout << ans << endl;
    return 0;
}
