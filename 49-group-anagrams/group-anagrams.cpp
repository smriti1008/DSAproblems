
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();

        vector<pair<string, string>> v;

        for (int i = 0; i < n; i++) {
            string key = strs[i];
            sort(key.begin(), key.end());

            v.push_back({key, strs[i]});
        }

        sort(v.begin(), v.end());

        vector<vector<string>> ans;

        for (int i = 0; i < n; ) {
            vector<string> group;
            string key = v[i].first;

            while (i < n && v[i].first == key) {
                group.push_back(v[i].second);
                i++;
            }

            ans.push_back(group);
        }

        return ans;
    }
};
