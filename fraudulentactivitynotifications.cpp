#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
using namespace std;

#define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'activityNotifications' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY expenditure
 *  2. INTEGER d
 */

int activityNotifications(vector<int> expenditure, int d) {
    ordered_set os;
    int size = expenditure.size();
    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < size; i++) {
        if (cnt < d) {
            os.insert(make_pair(expenditure[i], i));
            cnt++;
        } else {
            int s = 0;
            if (d % 2 == 0) {
                int m1 = (d / 2) - 1;
                int m2 = d / 2;
                int val1 = (*(os.find_by_order(m1))).first;
                int val2 = (*(os.find_by_order(m2))).first;
                s = val1 + val2;
                if (expenditure[i] >= s) ans++;
            } else {
                int m = d / 2;
                int val = (*(os.find_by_order(m))).first;
                s = val;
                if (expenditure[i] >= s * 2) ans++;
            }
            int idx_tbd = i - d;
            os.erase(os.find(make_pair(expenditure[idx_tbd], idx_tbd)));
            os.insert(make_pair(expenditure[i], i));
        }
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int d = stoi(first_multiple_input[1]);

    string expenditure_temp_temp;
    getline(cin, expenditure_temp_temp);

    vector<string> expenditure_temp = split(rtrim(expenditure_temp_temp));

    vector<int> expenditure(n);

    for (int i = 0; i < n; i++) {
        int expenditure_item = stoi(expenditure_temp[i]);

        expenditure[i] = expenditure_item;
    }

    int result = activityNotifications(expenditure, d);

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

