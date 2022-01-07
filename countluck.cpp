#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'countLuck' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING_ARRAY matrix
 *  2. INTEGER k
 */

array<int, 4> rm {1, -1, 0, 0};
array<int, 4> cm {0, 0, 1, -1};
array<array<bool, 105>, 105> visited;

int ans = 0;

bool isValid(vector<string> matrix, int i, int j, int n, int m) {
    if (i < 0 || j < 0) return false;
    if (i >= n || j >= m) return false;
    if (visited[i][j] || matrix[i][j] == 'X') return false;
    return true;
}

void dfs(vector<string> matrix, int i, int j, int n, int m, int cnt) {
    if (matrix[i][j] == '*')  {
        ans = cnt;
        return;
    }
    visited[i][j] = true;
    int tmp = 0;
    for (int k = 0; k < 4; k++) {
        int tr = i + rm[k];
        int tc = j + cm[k];
        if (isValid(matrix, tr, tc, n, m)) {
            tmp++;
        }
    }
    int curr = cnt;
    if (tmp > 1) curr++;
    for (int k = 0; k < 4; k++) {
        int tr = i + rm[k];
        int tc = j + cm[k];
        if (isValid(matrix, tr, tc, n, m)) {
            dfs(matrix, tr, tc, n, m, curr);
        }
    }
}

string countLuck(vector<string> matrix, int k) {
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = false;
        }
    }
    bool flag = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 'M') {
                int cnt = 0;
                ans = 0;
                dfs(matrix, i, j, n, m, cnt);
                if (ans == k) flag = true;
                break;
            }
        }
    }
    if (flag) return "Impressed";
    else return "Oops!";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int m = stoi(first_multiple_input[1]);

        vector<string> matrix(n);

        for (int i = 0; i < n; i++) {
            string matrix_item;
            getline(cin, matrix_item);

            matrix[i] = matrix_item;
        }

        string k_temp;
        getline(cin, k_temp);

        int k = stoi(ltrim(rtrim(k_temp)));

        string result = countLuck(matrix, k);

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

