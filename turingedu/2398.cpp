#include <iostream>
#include <string>
using namespace std;

string s, str;
int ans = 0;

int main() {
    cin >> s;
    while (cin >> str)
        if (str == s)
            ans++;
    cout << ans << endl;
    return 0;
}
