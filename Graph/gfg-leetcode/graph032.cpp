/*Cheapest Flights Within K Stops
https://leetcode.com/problems/cheapest-flights-within-k-stops/

There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

 

Example 1:


Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
Output: 700
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.
Example 2:


Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
Output: 200
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 2 is marked in red and has cost 100 + 100 = 200.
Example 3:


Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
Output: 500
Explanation:
The graph is shown above.
The optimal path with no stops from city 0 to 2 is marked in red and has cost 500.
 

Constraints:

1 <= n <= 100
0 <= flights.length <= (n * (n - 1) / 2)
flights[i].length == 3
0 <= fromi, toi < n
fromi != toi
1 <= pricei <= 104
There will not be any multiple flights between two cities.
0 <= src, dst, k < n
src != dst
*/
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Adjacency list creation
        vector<vector<pair<int,int>>> adj(n);
        for (auto it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        // BFS-like traversal using a queue
        queue<pair<int, pair<int, int>>> q; // {stops, {node, cost}}
        q.push({0, {src, 0}});

        // Initialize the price vector with infinity
        vector<int> price(n, 1e9);
        price[src] = 0;

        while (!q.empty()) {
            int stop = q.front().first;
            int node = q.front().second.first;
            int cost = q.front().second.second;
            q.pop();

            // If the number of stops exceeds k, we skip processing this path
            if (stop > k) {
                continue;
            }

            for (auto it : adj[node]) {
                int it_node = it.first;
                int dist = it.second;
                int d = cost + dist;

                // Push this path to the queue if it's cheaper and within the allowed stops
                if (d < price[it_node]) {
                    price[it_node] = d;
                    q.push({stop + 1, {it_node, d}});
                }
            }
        }

        // If we cannot reach the destination within k stops
        return price[dst] == 1e9 ? -1 : price[dst];
    }
};
// TC->O(E*flight.size());
