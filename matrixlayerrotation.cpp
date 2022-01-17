#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

vector<vector<int>> storeMatrix(int m, int n, vector<vector<int>> matrix) {
    int k = 0, l = 0;
    vector<vector<int>> tmp;
    int x = 1;
    int y = 1;
    vector<int> v;
    while (k < m && l < n) {
        if (k == x && l == y) {
            tmp.push_back(v);
            v.clear();
            x++;
            y++;
        }
        for (int i = l; i < n; ++i) v.push_back(matrix[k][i]);        
        k++;
        for (int i = k; i < m; ++i) v.push_back(matrix[i][n - 1]);
        n--;
        if (k < m) {
            for (int i = n - 1; i >= l; --i) v.push_back(matrix[m - 1][i]);
            m--;
        }
        if (l < n) {
            for (int i = m - 1; i >= k; --i) v.push_back(matrix[i][l]);
            l++;
        }
    }
    tmp.push_back(v);
    return tmp;
}

/*
 * Complete the 'matrixRotation' function below.
 *
 * The function accepts following parameters:
 *  1. 2D_INTEGER_ARRAY matrix
 *  2. INTEGER r
 */

void matrixRotation(vector<vector<int>> matrix, int r) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> v = storeMatrix(m, n, matrix);
    int k = 0, l = 0;
    int x = 1;
    int y = 1;
    int cnt = 0;
    int idx = 0;
    while (k < m && l < n) {
        if (k == x && l == y) {
            cnt++;
            idx = 0;
            x++;
            y++;
        }
        int size = v[cnt].size();
        int rot = r % size;
        for (int i = l; i < n; ++i) {
            int z = (idx + rot) % size;
            matrix[k][i] = v[cnt][z];
            idx++;
        }
        k++;
        for (int i = k; i < m; ++i) {
            int z = (idx + rot) % size;
            matrix[i][n - 1] = v[cnt][z];
            idx++;
        }
        n--;
        if (k < m) {
            for (int i = n - 1; i >= l; --i) {
                int z = (idx + rot) % size;
                matrix[m - 1][i] = v[cnt][z];
                idx++;
            }
            m--;
        }
        if (l < n) {
            for (int i = m - 1; i >= k; --i) {
                int z = (idx + rot) % size;
                matrix[i][l] = v[cnt][z];
                idx++;
            }
            l++;
        }
    }
    for (auto i : matrix) {
        for (auto j : i) cout << j << " ";
        cout << '\n';
    }
}

int main()
{
    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int m = stoi(first_multiple_input[0]);

    int n = stoi(first_multiple_input[1]);

    int r = stoi(first_multiple_input[2]);

    vector<vector<int>> matrix(m);

    for (int i = 0; i < m; i++) {
        matrix[i].resize(n);

        string matrix_row_temp_temp;
        getline(cin, matrix_row_temp_temp);

        vector<string> matrix_row_temp = split(rtrim(matrix_row_temp_temp));

        for (int j = 0; j < n; j++) {
            int matrix_row_item = stoi(matrix_row_temp[j]);

            matrix[i][j] = matrix_row_item;
        }
    }

    matrixRotation(matrix, r);

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

