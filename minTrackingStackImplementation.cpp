#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'processCouponStackOperations' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts STRING_ARRAY operations as parameter.
 */

vector<int> processCouponStackOperations(vector<string> operations) {
    stack<int> st, minSt;
    vector<int> result;

    for (string op : operations) {
        if (op.substr(0, 4) == "push") {
            int x = stoi(op.substr(5));
            st.push(x);

            if (minSt.empty() || x <= minSt.top()) {
                minSt.push(x);
            }
        }
        else if (op == "pop") {
            if (st.top() == minSt.top()) {
                minSt.pop();
            }
            st.pop();
        }
        else if (op == "top") {
            result.push_back(st.top());
        }
        else if (op == "getMin") {
            result.push_back(minSt.top());
        }
    }

    return result;
}

int main()
{
    string operations_count_temp;
    getline(cin, operations_count_temp);

    int operations_count = stoi(ltrim(rtrim(operations_count_temp)));

    vector<string> operations(operations_count);

    for (int i = 0; i < operations_count; i++) {
        string operations_item;
        getline(cin, operations_item);

        operations[i] = operations_item;
    }

    vector<int> result = processCouponStackOperations(operations);

    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i];

        if (i != result.size() - 1) {
            cout << "\n";
        }
    }

    cout << "\n";

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
