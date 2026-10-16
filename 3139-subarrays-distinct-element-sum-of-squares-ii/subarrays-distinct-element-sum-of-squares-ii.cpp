class Solution {
    static const int MOD = 1e9 + 7;

    vector<long long> tree, lazy;
    int n;

    void push(int node, int start, int end) {
        if (lazy[node] == 0) return;

        long long val = lazy[node];
        tree[node] = (tree[node] + val * (end - start + 1)) % MOD;

        if (start != end) {
            lazy[node * 2] = (lazy[node * 2] + val) % MOD;
            lazy[node * 2 + 1] = (lazy[node * 2 + 1] + val) % MOD;
        }

        lazy[node] = 0;
    }

    void update(int node, int start, int end,
                int l, int r, int val) {
        push(node, start, end);

        if (start > r || end < l) return;

        if (start >= l && end <= r) {
            lazy[node] = (lazy[node] + val) % MOD;
            push(node, start, end);
            return;
        }

        int mid = (start + end) / 2;

        update(node * 2, start, mid, l, r, val);
        update(node * 2 + 1, mid + 1, end, l, r, val);

        tree[node] = (tree[node * 2] +
                      tree[node * 2 + 1]) % MOD;
    }

    long long query(int node, int start, int end,
                    int l, int r) {
        push(node, start, end);

        if (start > r || end < l) return 0;

        if (start >= l && end <= r)
            return tree[node];

        int mid = (start + end) / 2;

        return (query(node * 2, start, mid, l, r) +
                query(node * 2 + 1, mid + 1, end, l, r))
                % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        n = nums.size();
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);

        unordered_map<int, int> last;
        long long sumSquares = 0;
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int l = 0;

            if (last.count(nums[i]))
                l = last[nums[i]] + 1;

            long long sum = query(1, 0, n - 1, l, i);
            long long len = i - l + 1;

            sumSquares = (sumSquares + 2 * sum + len) % MOD;

            update(1, 0, n - 1, l, i, 1);

            ans = (ans + sumSquares) % MOD;

            last[nums[i]] = i;
        }

        return ans;
    }
};