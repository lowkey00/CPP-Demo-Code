#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'encryption' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */
 
 char temp[85][85];

string encryption(string s) {
    int len = s.length();
    double x = sqrt(len);
    int col = ceil(x);
    int idx = 0;
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < col; j++) {
            temp[i][j] = '0';
        }
    }
    
    for (int i = 0; i < col; i++) {
        if (idx >= len) break;
        for (int j = 0; j < col; j++) {
           if (idx >= len) break;
           temp[i][j] = s[idx];
           idx++;
        }
    }
    string ans = "";
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < col; j++) {
            if (temp[j][i] != '0') ans += temp[j][i];
        }
        if (i != col - 1) {
            ans += " ";
        }
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

