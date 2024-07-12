//  Merge k Sorted Lists
// https://leetcode.com/problems/merge-k-sorted-lists/description/
/*
23. Merge k Sorted Lists
Solved
Hard
Topics
Companies
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 class compare {
public:
    // Overloading the operator() to create a min-heap based on node data
    bool operator()(ListNode* a, ListNode* b) { 
        return a->val > b->val;  // TC: O(1)
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Min-heap to store nodes
        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;
        int k = lists.size();

        if (k == 0) {
            return nullptr;
        }

        // Step 1: Insert the first node of each list into the min-heap
        for (int i = 0; i < k; i++) {
            if (lists[i] != nullptr) {
                minHeap.push(lists[i]);
            }
        }

        ListNode* head = nullptr;  // Pointer to the head of the merged list
        ListNode* tail = nullptr;  // Pointer to the last node of the merged list

        // While the heap is not empty
        while (!minHeap.empty()) {
            ListNode* top = minHeap.top();
            minHeap.pop();

            if (head == nullptr) {
                head = top;
                tail = top;
            } else {
                tail->next = top;
                tail = top;
            }

            if (top->next != nullptr) {
                minHeap.push(top->next);
            }
        }

        return head;
    }
};
