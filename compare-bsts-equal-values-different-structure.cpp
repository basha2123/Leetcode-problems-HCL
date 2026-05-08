#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'verifySameMultisetDifferentStructure' function below.
 *
 * The function is expected to return a BOOLEAN.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY root1
 *  2. INTEGER_ARRAY root2
 */

bool verifySameMultisetDifferentStructure(vector<int> root1, vector<int> root2) {

    const int NULL_NODE = 100001;
    vector<int> values1, values2;

    for (int x : root1) {
        if (x != NULL_NODE) {
            values1.push_back(x);
        }
    }

    for (int x : root2) {
        if (x != NULL_NODE) {
            values2.push_back(x);
        }
    }

    if (values1.size() != values2.size()) {
        return false;
    }

    sort(values1.begin(), values1.end());
    sort(values2.begin(), values2.end());

    if (values1 != values2) {
        return false;
    }

    if (root1.size() != root2.size()) {
        return true;
    }

    bool sameStructure = true;

    for (int i = 0; i < root1.size(); i++) {

        bool null1 = (root1[i] == NULL_NODE);
        bool null2 = (root2[i] == NULL_NODE);

        if (null1 != null2) {
            sameStructure = false;
            break;
        }
    }
    return !sameStructure;
}

int main()
{
    string root1_count_temp;
    getline(cin, root1_count_temp);

    int root1_count = stoi(ltrim(rtrim(root1_count_temp)));

    vector<int> root1(root1_count);

    for (int i = 0; i < root1_count; i++) {
        string root1_item_temp;
        getline(cin, root1_item_temp);

        int root1_item = stoi(ltrim(rtrim(root1_item_temp)));

        root1[i] = root1_item;
    }

    string root2_count_temp;
    getline(cin, root2_count_temp);

    int root2_count = stoi(ltrim(rtrim(root2_count_temp)));

    vector<int> root2(root2_count);

    for (int i = 0; i < root2_count; i++) {
        string root2_item_temp;
        getline(cin, root2_item_temp);

        int root2_item = stoi(ltrim(rtrim(root2_item_temp)));

        root2[i] = root2_item;
    }

    bool result = verifySameMultisetDifferentStructure(root1, root2);

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
