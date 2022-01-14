#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'steadyGene' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING gene as parameter.
 */

int steadyGene(string gene) {
    map<char, int> mp;
    int size = gene.size();
    int stb = size / 4;
    string tbr = "";
    for (auto c : gene) mp[c]++;
    for (auto i : mp) {
        if (i.second > stb) {
            int tmp = i.second;
            while (tmp != stb) {
                tbr += i.first;
                tmp--;
            }
        }
    }
    int ans = INT_MAX;
    int cnt = 0;
    mp.clear();
    for (auto c : tbr) {
        if(mp[c] == 0) cnt++;
        mp[c]++;
    }
    int i = 0;
    int j = 0;
    while (j < size) {
        mp[gene[j]]--;
        if (mp[gene[j]] == 0) cnt--;
        if (cnt == 0) {
            while (cnt == 0) {
                ans = min(ans, j - i + 1);
                mp[gene[i]]++;
                if (mp[gene[i]] > 0) cnt++;
                i++;
            }
        }
        j++;
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string gene;
    getline(cin, gene);

    int result = steadyGene(gene);

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

