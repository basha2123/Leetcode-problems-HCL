class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int> st;
        int operations = 0;

        for (int x : nums) {
            while (!st.empty() && st.top() > x) {
                st.pop();
            }

            if (x > 0 && (st.empty() || st.top() < x)) {
                st.push(x);
                operations++;
            }
        }

        return operations;
    }
};
