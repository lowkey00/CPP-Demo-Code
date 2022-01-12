#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'isValid' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string isValid(string s) {
    map<char, int> mp;
    for (auto c : s) mp[c]++;
    map<int, int> cnt;
    for (auto i : mp) cnt[i.second]++;
    bool flag = false;
    for (auto i : cnt) {
        if (i.second == 1) { 
            cnt[i.first]--;
            if (i.first - 1 > 0) cnt[i.first - 1]++;
            break;
        }
    }
    int tmp = 0;
    for (auto i : cnt) {
        if (i.second != 0) tmp++;
        if (tmp > 1) {
            flag = true;
            break;
        }
    }
    if (flag) return "NO";
    else return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

