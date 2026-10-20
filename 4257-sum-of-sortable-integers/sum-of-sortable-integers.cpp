class Solution {
public:
    bool canSort(vector<int>& nums, vector<int>& sorted, int k) {
        int n = nums.size();

        for (int i = 0; i < n; i += k) {
            vector<int> pat(k);

            for (int j = 0; j < k; j++) {
                pat[j] = sorted[i + j];
            }

            vector<int> lps(k, 0);

            for (int j = 1, len = 0; j < k;) {
                if (pat[j] == pat[len]) {
                    lps[j++] = ++len;
                } else if (len > 0) {
                    len = lps[len - 1];
                } else {
                    lps[j++] = 0;
                }
            }

            int j = 0;
            bool found = false;

            for (int t = 0; t < 2 * k - 1; t++) {
                int x = nums[i + t % k];

                while (j > 0 && x != pat[j]) {
                    j = lps[j - 1];
                }

                if (x == pat[j]) {
                    j++;
                }

                if (j == k) {
                    found = true;
                    break;
                }
            }

            if (!found) return false;
        }

        return true;
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        int ans = 0;

        for (int d = 1; d <= n / d; d++) {
            if (n % d != 0) continue;

            if (canSort(nums, sorted, d)) {
                ans += d;
            }

            int other = n / d;

            if (other != d && canSort(nums, sorted, other)) {
                ans += other;
            }
        }

        return ans;
    }
};