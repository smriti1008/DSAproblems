class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size(), m = word2.size();

        vector<int> suf(m, -1);
        int i = n - 1;
        for (int j = m - 1; j >= 0; j--) {
            while (i >= 0 && word1[i] != word2[j]) i--;
            if (i < 0) break;
            suf[j] = i;
            i--;
        }

        vector<int> ans;
        int p = 0;
        bool used = false;

        for (int j = 0; j < m; j++) {
            bool ok = false;

            while (p < n) {

                if (word1[p] == word2[j]) {
                    ans.push_back(p);
                    p++;
                    ok = true;
                    break;
                }

                if (!used) {
                    bool can =
                        (j == m - 1) ||
                        (suf[j + 1] != -1 && p < suf[j + 1]);

                    if (can) {
                        used = true;
                        ans.push_back(p);
                        p++;
                        ok = true;
                        break;
                    }
                }

                p++;
            }

            if (!ok) return {};
        }

        return ans;
    }
};