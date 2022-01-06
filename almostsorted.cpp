#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'almostSorted' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

void almostSorted(vector<int> arr) {
    int size = arr.size();
    vector<int> tmp = arr;
    sort(tmp.begin(), tmp.end());
    vector<pair<int, int>> err;
    for (int i = 0; i < size; i++) {
        if (arr[i] != tmp[i]) {
            err.push_back(make_pair(i, arr[i]));
        }
    }
    int err_t = err.size();
    if (err_t == 2) {
        cout << "yes\nswap " << err[0].first + 1 << " " << err[1].first + 1 << '\n';
    } else {
        bool flag = false;
        for (int i = 0; i < err_t - 1; i++) {
            if (err[i].second < err[i + 1].second) {
                flag = true;
                break;
            }
        }
        if (flag) cout << "no\n";
        else cout << "yes\nreverse " << err[0].first + 1 << " " << err[err_t - 1].first + 1 << '\n';
    }
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    almostSorted(arr);

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

