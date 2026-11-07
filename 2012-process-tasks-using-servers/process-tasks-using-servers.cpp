#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();
        
        // Min-heap for free servers: stores {weight, index}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> free_servers;
        for (int i = 0; i < n; ++i) {
            free_servers.push({servers[i], i});
        }
        
        // Min-heap for busy servers: stores {free_time, weight, index}
        priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> busy_servers;
        
        vector<int> ans(m);
        long long current_time = 0;
        
        for (int j = 0; j < m; ++j) {
            current_time = max(current_time, (long long)j);
            
            // If no servers are free, fast-forward time to when the next server becomes free
            if (free_servers.empty()) {
                current_time = max(current_time, get<0>(busy_servers.top()));
            }
            
            // Release all servers that have finished their tasks by current_time
            while (!busy_servers.empty() && get<0>(busy_servers.top()) <= current_time) {
                auto [free_time, weight, index] = busy_servers.top();
                busy_servers.pop();
                free_servers.push({weight, index});
            }
            
            // Assign the task to the best available server
            auto [weight, index] = free_servers.top();
            free_servers.pop();
            
            ans[j] = index;
            busy_servers.push({current_time + tasks[j], weight, index});
        }
        
        return ans;
    }
};