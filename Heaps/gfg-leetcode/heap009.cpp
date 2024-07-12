// Merge k Sorted Arrays
// https://www.geeksforgeeks.org/problems/merge-k-sorted-arrays/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

/*
Merge k Sorted Arrays
Difficulty: MediumAccuracy: 67.25%Submissions: 91K+Points: 4
Given k sorted arrays arranged in the form of a matrix of size k * k. The task is to merge them into one sorted array. Return the merged sorted array ( as a pointer to the merged sorted arrays in cpp, as an ArrayList in java, and list in python).


Examples :

Input: k = 3, arr[][] = {{1,2,3},{4,5,6},{7,8,9}}
Output: 1 2 3 4 5 6 7 8 9
Explanation: Above test case has 3 sorted arrays of size 3, 3, 3 arr[][] = [[1, 2, 3],[4, 5, 6],[7, 8, 9]]. The merged list will be [1, 2, 3, 4, 5, 6, 7, 8, 9].
Input: k = 4, arr[][]={{1,2,3,4},{2,2,3,4},{5,5,6,6},{7,8,9,9}}
Output: 1 2 2 2 3 3 4 4 5 5 6 6 7 8 9 9 
Explanation: Above test case has 4 sorted arrays of size 4, 4, 4, 4 arr[][] = [[1, 2, 2, 2], [3, 3, 4, 4], [5, 5, 6, 6], [7, 8, 9, 9 ]]. The merged list will be [1, 2, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 8, 9, 9].
Expected Time Complexity: O(k2*Log(k))
Expected Auxiliary Space: O(k2)
*/
class node {
    public:
        int data;  // TC: O(1)
        int i;     // TC: O(1)
        int j;     // TC: O(1)

        // Constructor to initialize a node
        node(int data, int row, int col) {
            this->data = data;  // TC: O(1)
            this->i = row;  // TC: O(1)
            this->j = col;  // TC: O(1)
        }
};

// Comparator class for the priority queue
class compare {
    public:
        // Overloading the operator() to create a min-heap based on node data
        bool operator()(node* a, node* b) { 
            return a->data > b->data;  // TC: O(1)
        }
};

// Solution class
class Solution {
    public:
        // Function to merge k sorted arrays
        vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
            // Min-heap to store nodes
            priority_queue<node*, vector<node*>, compare> minHeap;  // TC: O(1)
            vector<int> ans;  // TC: O(1)

            // Step 1: Insert the first element of each array into the min-heap
            for (int i = 0; i < K; i++) {  // TC: O(K)
                node* tmp = new node(arr[i][0], i, 0);  // TC: O(1)
                minHeap.push(tmp);  // TC: O(log K)
            }

            // While the heap is not empty
            while (minHeap.size() > 0) {  // TC: O(N log K), where N is the total number of elements
                node* tmp = minHeap.top();  // TC: O(1)
                ans.push_back(tmp->data);   // TC: O(1)
                minHeap.pop();  // TC: O(log K)

                int i = tmp->i;  // TC: O(1)
                int j = tmp->j;  // TC: O(1)

                // If there is another element in the same row
                if (j + 1 < arr[i].size()) {  // TC: O(1)
                    node* next = new node(arr[i][j + 1], i, j + 1);  // TC: O(1)
                    minHeap.push(next);  // TC: O(log K)
                }
            }
            return ans;  // TC: O(1)
        }
};

TC->O(n*K logK)
SC->O(K)+O(n*K)->O(n*K)
