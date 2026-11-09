#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        // Min-heap to store busy servers: {free_time, server_id}
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busy;
        
        // Set to store currently available server IDs
        set<int> available;
        for (int i = 0; i < k; ++i) {
            available.insert(i);
        }
        
        vector<int> request_count(k, 0);
        int max_handled = 0;
        
        for (int i = 0; i < arrival.size(); ++i) {
            long long curr_time = arrival[i];
            
            // Free up servers whose tasks have finished by curr_time
            while (!busy.empty() && busy.top().first <= curr_time) {
                available.insert(busy.top().second);
                busy.pop();
            }
            
            // If all servers are busy, drop the request
            if (available.empty()) {
                continue;
            }
            
            // Find the first available server >= (i % k)
            int target = i % k;
            auto it = available.lower_bound(target);
            
            // If none found, wrap around to the beginning of the set
            if (it == available.end()) {
                it = available.begin();
            }
            
            int assigned_server = *it;
            available.erase(it);
            
            // Assign the task to the server
            busy.push({curr_time + load[i], assigned_server});
            request_count[assigned_server]++;
            max_handled = max(max_handled, request_count[assigned_server]);
        }
        
        // Collect all servers that handled the maximum number of requests
        vector<int> result;
        for (int i = 0; i < k; ++i) {
            if (request_count[i] == max_handled) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};