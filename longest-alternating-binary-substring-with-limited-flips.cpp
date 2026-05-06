#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'longestAlternatingSubstring' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER k
 */

int solvePattern(const string &s, int k, char start) {
    int n = s.size();
    int left = 0, mismatch = 0, maxLen = 0;

    for (int right = 0; right < n; right++) {
        char expected = (right % 2 == 0) ? start : (start == '0' ? '1' : '0');

        if (s[right] != expected) mismatch++;

        while (mismatch > k) {
            char leftExpected = (left % 2 == 0) ? start : (start == '0' ? '1' : '0');
            if (s[left] != leftExpected) mismatch--;
            left++;
        }

        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}

int longestAlternatingSubstring(string s, int k) {
    if (s.empty()) return 0;

    int case1 = solvePattern(s, k, '0'); // 010101...
    int case2 = solvePattern(s, k, '1'); // 101010...

    return max(case1, case2);
}

int main()
{
    string s;
    getline(cin, s);

    string k_temp;
    getline(cin, k_temp);

    int k = stoi(ltrim(rtrim(k_temp)));

    int result = longestAlternatingSubstring(s, k);

    cout << result << "\n";

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
