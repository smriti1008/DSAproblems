class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges,
                     string labels, int k) {

        vector<vector<pair<int,int>>> adj(n);

        // Build adjacency list
        for(auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
        }

        // dist[node][count]
        vector<vector<long long>> dist(n,
            vector<long long>(k + 1, LLONG_MAX));

        // {cost, node, count}
        priority_queue<
            tuple<long long,int,int>,
            vector<tuple<long long,int,int>>,
            greater<tuple<long long,int,int>>
        > pq;

        // Starting node
        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while(!pq.empty()) {

            auto [cost, node, count] = pq.top();
            pq.pop();

            if(cost != dist[node][count])
                continue;

            // Destination reached
            if(node == n - 1)
                return cost;

            for(auto &it : adj[node]) {

                int nextNode = it.first;
                int wt = it.second;

                int newCount;

                if(labels[node] == labels[nextNode]) {
                    newCount = count + 1;
                }
                else {
                    newCount = 1;
                }

                // More than k consecutive characters
                if(newCount > k)
                    continue;

                long long newCost = cost + wt;

                if(newCost < dist[nextNode][newCount]) {

                    dist[nextNode][newCount] = newCost;

                    pq.push({
                        newCost,
                        nextNode,
                        newCount
                    });
                }
            }
        }

        return -1;
    }
};