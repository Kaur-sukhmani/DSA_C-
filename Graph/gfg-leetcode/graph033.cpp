/*Minimum Multiplications to reach End
https://www.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/0

Given start, end and an array arr of n numbers. At each step, start is multiplied with any number in the array and then mod operation with 100000 is done to get the new start.

Your task is to find the minimum steps in which end can be achieved starting from start. If it is not possible to reach end, then return -1.

Example 1:

Input:
arr[] = {2, 5, 7}
start = 3, end = 30
Output:
2
Explanation:
Step 1: 3*2 = 6 % 100000 = 6 
Step 2: 6*5 = 30 % 100000 = 30
Example 2:

Input:
arr[] = {3, 4, 65}
start = 7, end = 66175
Output:
4
Explanation:
Step 1: 7*3 = 21 % 100000 = 21 
Step 2: 21*3 = 63 % 100000 = 63 
Step 3: 63*65 = 4095 % 100000 = 4095 
Step 4: 4095*65 = 266175 % 100000 = 66175
Your Task:
You don't need to print or input anything. Complete the function minimumMultiplications() which takes an integer array arr, an integer start and an integer end as the input parameters and returns an integer, denoting the minumum steps to reach in which end can be achieved starting from start.

Expected Time Complexity: O(105)
Expected Space Complexity: O(105)

Constraints:

1 <= n <= 104
1 <= arr[i] <= 104
1 <= start, end < 105
*/
class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        int n = arr.size();
        queue<pair<int,int>> q;
        q.push({start, 0});

        vector<bool> visited(100000, false);
        visited[start] = true;

        while (!q.empty()) {
            int ans = q.front().first;
            int count = q.front().second;
            q.pop();

            // If we've reached the end, return the number of steps
            if (ans == end) {
                return count;
            }

            for (int i = 0; i < n; i++) {
                int ansStore = (ans * arr[i]) % 100000;

                // If this state hasn't been visited, add it to the queue
                if (!visited[ansStore]) {
                    visited[ansStore] = true;
                    q.push({ansStore, count + 1});
                }
            }
        }
        
        // If we cannot reach the end value
        return -1;
    }
};
