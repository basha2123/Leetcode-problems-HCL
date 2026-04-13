#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'getAutoSaveInterval' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts INTEGER n as parameter.
 */

long getAutoSaveInterval(int n) {
   if(n==0) return 1;
   if(n==1) return 2;
    
    long a=1, b=2;
    for(int i=2;i<=n;i++){
        long c=a+b;
        a=b;
        b=c;
    }
    return b;
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    long result = getAutoSaveInterval(n);

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
