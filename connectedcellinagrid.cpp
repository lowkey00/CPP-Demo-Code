#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'connectedCell' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY matrix as parameter.
 */
 
array<int, 8> rm {-1, -1, -1, 0, 0, 1, 1, 1};
array<int, 8> cm {-1, 0, 1, -1, 1, -1, 0, 1};

array<array<bool, 15>, 15> visited;

int cnt = 0;

bool isValid(int i, int j, int n, int m, vector<vector<int>> matrix) {
    if (i < 0 || j < 0) return false;
    if (i >= n || j >= m) return false;
    if (visited[i][j]) return false;
    if (matrix[i][j] != 1) return false;
    return true;
}

void dfs(vector<vector<int>> matrix, int i, int j, int n, int m) {
    visited[i][j] = true;
    for (int k = 0; k < 8; k++) {
        int tr = i + rm[k];
        int tc = j + cm[k];
        if (isValid(tr, tc, n, m, matrix)) {
            cnt++;
            dfs(matrix, tr, tc, n, m);
        } 
    }
}

int connectedCell(vector<vector<int>> matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = false;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] && !visited[i][j]) {
                cnt = 1;
                dfs(matrix, i, j, n, m);
                ans = max(ans, cnt);
            }        
        }
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string m_temp;
    getline(cin, m_temp);

    int m = stoi(ltrim(rtrim(m_temp)));

    vector<vector<int>> matrix(n);

    for (int i = 0; i < n; i++) {
        matrix[i].resize(m);

        string matrix_row_temp_temp;
        getline(cin, matrix_row_temp_temp);

        vector<string> matrix_row_temp = split(rtrim(matrix_row_temp_temp));

        for (int j = 0; j < m; j++) {
            int matrix_row_item = stoi(matrix_row_temp[j]);

            matrix[i][j] = matrix_row_item;
        }
    }

    int result = connectedCell(matrix);

    fout << result << "\n";

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

