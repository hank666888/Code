#include <iostream>
#include <string>
using namespace std

string s, str, now;
bool flag, vis;
int ans1, ans2;

int main() {
    cin >> s;
    for (int i = 0; i < s.size(); i++)
       if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] += 'a' - 'A';
    string k;
    getline(cin, k);
    getline(cin, str);
    for (int i = 0; i  < str.size(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 'a' - 'A';
    }
    for (int i = 0; i < str.size(); i++) {
        if (str[i] != ' '){
            now += str[i];
            flag = false;
        }
        if ( (str[i] == ' ' && !flag) || i == str.size() - 1) {
            if (now == s) {
                if (!vis){
                    ans2 = i - s.size();
                    vis = true;
                }
                ans1++;
            }
            now = "";
            flag = true;
        }
    }
    if (ans1 == 0)
        cout << -1 <<endl;
    else
        cout << ans1 << " " << ans2 << endl;
    return 0;
}
