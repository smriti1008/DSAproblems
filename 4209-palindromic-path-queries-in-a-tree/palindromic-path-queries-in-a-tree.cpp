class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges,
                                string s, vector<string>& queries) {
        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        vector<vector<int>> up(LOG, vector<int>(n));
        vector<int> tin(n), tout(n), depth(n);
        vector<int> base(n);

        int timer = 0;

        function<void(int, int, int)> dfs =
            [&](int u, int p, int parentMask) {
                tin[u] = ++timer;

                up[0][u] = p;
                for (int j = 1; j < LOG; j++) {
                    up[j][u] = up[j - 1][up[j - 1][u]];
                }

                int bit = 1 << (s[u] - 'a');
                base[u] = parentMask ^ bit;

                for (int v : adj[u]) {
                    if (v == p) continue;

                    depth[v] = depth[u] + 1;
                    dfs(v, u, base[u]);
                }

                tout[u] = timer;
            };

        dfs(0, 0, 0);

        // Fenwick tree supporting range XOR updates
        // and point queries.
        vector<int> bit(n + 2, 0);

        auto add = [&](int idx, int val) {
            for (int i = idx; i <= n; i += i & -i) {
                bit[i] ^= val;
            }
        };

        auto rangeUpdate = [&](int l, int r, int val) {
            add(l, val);
            if (r + 1 <= n) add(r + 1, val);
        };

        auto pointQuery = [&](int idx) {
            int result = 0;

            for (int i = idx; i > 0; i -= i & -i) {
                result ^= bit[i];
            }

            return result;
        };

        auto getRootMask = [&](int u) {
            return base[u] ^ pointQuery(tin[u]);
        };

        auto lca = [&](int u, int v) {
            if (depth[u] < depth[v]) swap(u, v);

            int diff = depth[u] - depth[v];

            for (int j = 0; j < LOG; j++) {
                if (diff & (1 << j)) {
                    u = up[j][u];
                }
            }

            if (u == v) return u;

            for (int j = LOG - 1; j >= 0; j--) {
                if (up[j][u] != up[j][v]) {
                    u = up[j][u];
                    v = up[j][v];
                }
            }

            return up[0][u];
        };

        vector<bool> answer;

        for (string &q : queries) {
            string type;
            int u;
            char c;

            stringstream ss(q);
            ss >> type >> u;

            if (type == "update") {
                ss >> c;

                int oldMask = 1 << (s[u] - 'a');
                int newMask = 1 << (c - 'a');

                int delta = oldMask ^ newMask;

                rangeUpdate(tin[u], tout[u], delta);

                s[u] = c;
            } 
            else {
                int v;
                ss >> v;

                int w = lca(u, v);

                int mask = getRootMask(u)
                         ^ getRootMask(v)
                         ^ (1 << (s[w] - 'a'));

                answer.push_back(
                    (mask & (mask - 1)) == 0
                );
            }
        }

        return answer;
    }
};