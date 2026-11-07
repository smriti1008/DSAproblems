class Solution {
public:
    string removeDuplicates(string s, int k) {

        stack<pair<char, int>> st;

        for (char ch : s) {

            if (!st.empty() && st.top().first == ch) {
                st.top().second++;
            }
            else {
                st.push({ch, 1});
            }

            if (st.top().second == k) {
                st.pop();
            }
        }

        string ans = "";

        while (!st.empty()) {
            char ch = st.top().first;
            int count = st.top().second;

            ans.append(count, ch);

            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};