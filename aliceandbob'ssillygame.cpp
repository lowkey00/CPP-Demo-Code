#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'sillyGame' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER n as parameter.
 */

string sillyGame(int n) {
    vector<bool> p;
    for(int i = 0; i <= n; i++) p.push_back(true);
    p[0] = p[1] = false;
    for(int i = 2; i * i <= n; i++) {
        if (p[i]) {
            for (int j = i * i; j <= n; j += i) p[j] = false;
        }
    }
    int cnt = 0;
    for (int i = 2; i <= n; i++) if (p[i]) cnt++;
    if (cnt % 2 == 0) return "Bob";
    else return "Alice";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string g_temp;
    getline(cin, g_temp);

    int g = stoi(ltrim(rtrim(g_temp)));

    for (int g_itr = 0; g_itr < g; g_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string result = sillyGame(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

