#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'lilysHomework' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

int lilysHomework(vector<int> arr) {
    map<int, int> mp_asc;
    map<int, int> idx_asc;
    map<int, int> mp_desc;
    map<int, int> idx_desc;
    int size = arr.size();
    for (int i = 0; i < size; i++) {
        mp_asc[arr[i]] = i;
        idx_asc[i] = arr[i];
        mp_desc[arr[i]] = i;
        idx_desc[i] = arr[i];
    }
    sort(arr.begin(), arr.end());
    int asc_poss = 0;
    int desc_poss = 0;
    int cnt_asc = 0;
    int cnt_desc = size - 1;
    for (auto val : arr) {
        if (idx_asc[cnt_asc] != val) {
            asc_poss++;
            int tmp_val = idx_asc[cnt_asc];
            int tmp_idx = mp_asc[val];
            idx_asc[cnt_asc] = val;
            idx_asc[tmp_idx] = tmp_val;
            mp_asc[val] = cnt_asc;
            mp_asc[tmp_val] = tmp_idx;
        }
        if (idx_desc[cnt_desc] != val) {
            desc_poss++;
            int tmp_val = idx_desc[cnt_desc];
            int tmp_idx = mp_desc[val];
            idx_desc[cnt_desc] = val;
            idx_desc[tmp_idx] = tmp_val;
            mp_desc[val] = cnt_desc;
            mp_desc[tmp_val] = tmp_idx;
        }
        cnt_asc++;
        cnt_desc--;
    }
    int ans = min(asc_poss, desc_poss);
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

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

    int result = lilysHomework(arr);

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

