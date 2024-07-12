// Smallest Range Covering Elements from K Lists
// https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/description/
/*
632. Smallest Range Covering Elements from K Lists
Solved
Hard
Topics
Companies
You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.

We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.

 

Example 1:

Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
Output: [20,24]
Explanation: 
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].
Example 2:

Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
Output: [1,1]
 

Constraints:

nums.length == k
1 <= k <= 3500
1 <= nums[i].length <= 50
-105 <= nums[i][j] <= 105
nums[i] is sorted in non-decreasing order.
*/
#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    int row;
    int col;

    node(int d, int r, int c) {
        data = d;
        row = r;
        col = c;
    }
};

class compare {
public:
    bool operator()(node* a, node* b) {
        return a->data > b->data; // For min-heap
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();  // Number of lists
        int mini = INT_MAX;
        int maxi = INT_MIN;
        priority_queue<node*, vector<node*>, compare> minHeap;

        // Initialize the minHeap and find the initial mini and maxi
        for (int i = 0; i < k; i++) {
            int element = nums[i][0];
            mini = min(mini, element);
            maxi = max(maxi, element);
            minHeap.push(new node(element, i, 0));
        }

        int start = mini;
        int end = maxi;

        while (!minHeap.empty()) {
            node* temp = minHeap.top();
            minHeap.pop();
            mini = temp->data;

            // Update the range if the current range is smaller
            if (maxi - mini < end - start) {
                start = mini;
                end = maxi;
            }

            // Move to the next element in the row of the popped element
            if (temp->col + 1 < nums[temp->row].size()) {
                maxi = max(maxi, nums[temp->row][temp->col + 1]);
                minHeap.push(new node(nums[temp->row][temp->col + 1], temp->row, temp->col + 1));
            } else {
                // If any list is exhausted, break out of the loop
                break;
            }
        }

        return {start, end};
    }
};
