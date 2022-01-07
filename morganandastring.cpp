#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'morganAndString' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING a
 *  2. STRING b
 */

string morganAndString(string a, string b) {
    string x = a + "z";
    string y = b + "z";
    string ans = "";
    int ptr1 = 0;
    int ptr2 = 0;
    int len1 = a.length();
    int len2 = b.length();
    while (ptr1 < len1 || ptr2 < len2) {
        if (x.compare(ptr1, (len1 + 1) - ptr1, y, ptr2, (len2 + 1) - ptr2) > 0) {
            ans += y[ptr2];
            ptr2++;
        } else {
            ans += x[ptr1];
            ptr1++;
        } 
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string a;
        getline(cin, a);

        string b;
        getline(cin, b);

        string result = morganAndString(a, b);

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

