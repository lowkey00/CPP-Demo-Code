#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'surfaceArea' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY A as parameter.
 */

int surfaceArea(vector<vector<int>> A) {
    int h = A.size();
    int w = A[0].size();
    int area_bot_top = h * w * 2;
    int area_left_right = 0;
    int area_front_back = 0;
    
    for (int i = 0; i < h; i++) {
        int prev = -1;
        for (int j = 0; j < w; j++) {
            if (j == 0) area_left_right += A[i][j];
            else {
                if (prev < A[i][j]) area_left_right += (A[i][j] - prev);
            }
            prev = A[i][j];
        }
    }
    for (int i = 0; i < h; i++) {
        int prev = -1;
        for (int j = w - 1; j >= 0; j--) {
            if (j == w - 1) area_left_right += A[i][j];
            else {
                if (prev < A[i][j]) area_left_right += (A[i][j] - prev);
            }
            prev = A[i][j];
        }
    }
    for (int i = 0; i < w; i++) {
        int prev = -1;
        for (int j = 0; j < h; j++) {
            if (j == 0) area_front_back += A[j][i];
            else {
                if (prev < A[j][i]) area_front_back += (A[j][i] - prev);
            }
            prev = A[j][i];
        }
    }
    for (int i = 0; i < w; i++) {
        int prev = -1;
        for (int j = h - 1; j >= 0; j--) {
            if (j == h - 1) area_front_back += A[j][i];
            else {
                if (prev < A[j][i]) area_front_back += (A[j][i] - prev);
            }
            prev = A[j][i];
        }
    }
    
    int total_area = area_bot_top + area_front_back + area_left_right;
    
    return total_area;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int H = stoi(first_multiple_input[0]);

    int W = stoi(first_multiple_input[1]);

    vector<vector<int>> A(H);

    for (int i = 0; i < H; i++) {
        A[i].resize(W);

        string A_row_temp_temp;
        getline(cin, A_row_temp_temp);

        vector<string> A_row_temp = split(rtrim(A_row_temp_temp));

        for (int j = 0; j < W; j++) {
            int A_row_item = stoi(A_row_temp[j]);

            A[i][j] = A_row_item;
        }
    }

    int result = surfaceArea(A);

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

