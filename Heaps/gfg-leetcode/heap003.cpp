// Kth Largest Element in an Array
// https://leetcode.com/problems/kth-largest-element-in-an-array/
/*
Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

 

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
 

Constraints:

1 <= k <= nums.length <= 105
-104 <= nums[i] <= 104
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Min heap to keep track of the k largest elements
        priority_queue<int, vector<int>, greater<int>> minHeap;

        // Insert the first k elements into the min heap
        for(int i = 0; i < k; i++){
            minHeap.push(nums[i]);
        }

        // Process the remaining elements
        for(int i = k; i < nums.size(); i++){
            if(nums[i] > minHeap.top()){
                minHeap.pop();
                minHeap.push(nums[i]);
            }
        }

        // The root of the min heap is the k-th largest element
        return minHeap.top();
    }
};
