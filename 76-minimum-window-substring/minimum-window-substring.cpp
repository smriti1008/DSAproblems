class Solution {
public:
    string minWindow(string s, string t) {
        int total = t.size();
        vector<int> m(256, 0);
        int start = 0, end = 0, index = -1;
        for (char c : t) {
            m[c]++;
        }
        int ans = INT_MAX;

        while (end < s.size()) {
            m[s[end]]--;
            if (m[s[end]] >= 0)
                total--;

            while (!total && start <= end) {

                if (ans > end - start + 1) {
                    ans = end - start + 1;
                    index = start;
                }
                m[s[start]]++;
                if (m[s[start]] > 0)
                    total++;

                start++;
            }

            end++;
        }
        if (index == -1)
            return "";

        string str = "";
        for (int i = index; i < index + ans; i++) {
            str += s[i];
        }
        return str;
    }
};