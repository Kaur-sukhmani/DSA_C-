// Move Zeroes to the last of the array 
// https://leetcode.com/problems/move-zeroes/description/
/*
Move Zeroes

Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

 

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]
 


*/
// MY APPROACH BUT TIME COMPLEXITY IS O
/*
TC->O(N^2)
SC-> O(1)
*/
class Solution {
public:
    int findFirstnonzeroIndex(int index, const vector<int>& nums) {
        int n = nums.size();
        for (int i = index + 1; i < n; i++) {
            if (nums[i] != 0) {
                return i;
            }
        }
        return index; // Return the current index if no non-zero element is found
    }

    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                int index = findFirstnonzeroIndex(i, nums);
                if (index != i) { // Only swap if a non-zero element is found
                    swap(nums[i], nums[index]);
                }
            }
        }
    }
};


// OPTIMIZED->
// TC->is O(N)
// SC-> O(1)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int lastNonZeroFoundAt = 0; // Keeps track of the position of the last found non-zero element

        // Move all non-zero elements to the front
        for (int i = 0; i < n; ++i) {
            if (nums[i] != 0) {
                swap(nums[lastNonZeroFoundAt++], nums[i]);
            }
        }
    }
};
/*
lastNonZeroFoundAt: This pointer keeps track of the position where the next non-zero element should be placed.
i: This pointer iterates over the array.
*/
