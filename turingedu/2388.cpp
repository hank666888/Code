#include <iostream>
#include <string>
using namespace std;

string s;
bool flag;
int ans, k;

int main() {
    getline(cin, s);
    for(int i = 0; i < s.size(); i++)
        if (s[i] != ' ') {
            k = i;
            break;
        }
    for (int i = k; i < s.size(); i++) {
        if (s[i] == ' ')
            if (!flag) {
                flag = true;
                ans++;
            }
        if (s[i] != ' ')
            flag = false;
    }
    if (!flag)
        ans++;
    cout << ans << endl;
    return 0;
}
