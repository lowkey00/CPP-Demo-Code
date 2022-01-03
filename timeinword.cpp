#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'timeInWords' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. INTEGER h
 *  2. INTEGER m
 */

string timeInWords(int h, int m) {
    map<int, string> mp;
    mp[0] = "o' clock";
    mp[1] = "one";
    mp[2] = "two";
    mp[3] = "three";
    mp[4] = "four";
    mp[5] = "five";
    mp[6] = "six";
    mp[7] = "seven";
    mp[8] = "eight";
    mp[9] = "nine";
    mp[10] = "ten";
    mp[11] = "eleven";
    mp[12] = "twelve";
    mp[13] = "thirteen";
    mp[14] = "fourteen";
    mp[15] = "quarter";
    mp[16] = "sixteen";
    mp[17] = "seventeen";
    mp[18] = "eighteen";
    mp[19] = "nineteen";
    mp[20] = "twenty";
    mp[21] = "twenty one";
    mp[22] = "twenty two";
    mp[23] = "twenty three";
    mp[24] = "twenty four";
    mp[25] = "twenty five";
    mp[26] = "twenty six";
    mp[27] = "twenty seven";
    mp[28] = "twenty eight";
    mp[29] = "twenty nine";
    mp[30] = "half";
    if (m == 0) {
        return mp[h] + " " + mp[m];
    } else {
        if (m <= 30) {
            string ans = mp[m];
            if (m != 15 && m != 30) {
                ans += " minute";
                if (m > 1) ans += "s";
            } 
            ans += " past " + mp[h];
            return ans;
        } else {
            int x = 60 - m;
            string ans = mp[x];
            if (x != 15 && x != 30) {
                ans += " minute";
                if (x > 1) ans += "s";
            } 
            ans += " to " + mp[h + 1];
            return ans;
        }
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string h_temp;
    getline(cin, h_temp);

    int h = stoi(ltrim(rtrim(h_temp)));

    string m_temp;
    getline(cin, m_temp);

    int m = stoi(ltrim(rtrim(m_temp)));

    string result = timeInWords(h, m);

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

