// Kth Smallest
// https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1
/*
Given an array arr[] and an integer k where k is smaller than the size of the array, the task is to find the kth smallest element in the given array. It is given that all array elements are distinct.

Note:-  l and r denotes the starting and ending index of the array.

Example 1:

Input:
n = 6
arr[] = 7 10 4 3 20 15
k = 3
l=0 r=5

Output : 
7

Explanation :
3rd smallest element in the given 
array is 7.
Example 2:

Input:
n = 5
arr[] = 7 10 4 20 15
k = 4 
l=0 r=4

Output : 
15

Explanation :
4th smallest element in the given 
array is 15.
Your Task:
You don't have to read input or print anything. Your task is to complete the function kthSmallest() which takes the array arr[], integers l and r denoting the starting and ending index of the array and an integer k as input and returns the kth smallest element.
 
Expected Time Complexity: O(n*log(n) )
Expected Auxiliary Space: O(log(n))
Constraints:
1 <= n <= 105
l = 0
r = N-1
1<= arr[i] <= 105
1 <= k <= n
*/
// 
//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    
    // APPROACH 1:
    int kthSmallest(int arr[], int l, int r, int k) {
        // Using a max heap to find the k-th smallest element
        priority_queue<int> pq;
        for(int i = l; i <= r; i++){
            pq.push(arr[i]);
            if(pq.size() > k){
                pq.pop();
            }
        }
        return pq.top();
    }

    // APPROACH 2:
    int kthSmallest2(int arr[], int l, int r, int k) {
        // Using a max heap to find the k-th smallest element
        priority_queue<int> pq;
        // Insert first k elements into the max heap
        for(int i = l; i < k; i++){
            pq.push(arr[i]);
        }
        // Process the remaining elements
        for(int i = k; i <= r; i++){
            if(arr[i] < pq.top()){
                pq.push(arr[i]);
                pq.pop();
            }
        }
        return pq.top();
    }
};

//{ Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i = 0; i < number_of_elements; i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout << "Using Approach 1: " << ob.kthSmallest(a, 0, number_of_elements-1, k) << endl;
        cout << "Using Approach 2: " << ob.kthSmallest2(a, 0, number_of_elements-1, k) << endl;
    }
    return 0;
}
// } Driver Code Ends
/*
Explanation:
Approach 1:

Heap Initialization: Initialize a max heap (priority queue).
Heap Insertion: Insert all elements from the array into the max heap.
Heap Size Control: Ensure that the heap size does not exceed k. If it does, remove the largest element.
Result: The top of the heap (pq.top()) is the k-th smallest element.
This approach has a time complexity of 
𝑂
(
𝑛
log
⁡
𝑘
)
O(nlogk), where 
𝑛
n is the number of elements in the array and 
𝑘
k is the size of the heap.

Approach 2:

Heap Initialization: Initialize a max heap (priority queue).
First k Elements: Insert the first k elements of the array into the max heap.
Remaining Elements: For each remaining element in the array, compare it with the top of the heap:
If the current element is smaller than the heap's top, push it into the heap and remove the top element.
Result: After processing all elements, the top of the heap (pq.top()) is the k-th smallest element.
This approach also has a time complexity of 
𝑂
(
𝑛
log
⁡
𝑘
)
O(nlogk) but is more efficient in practice because:

The heap only needs to maintain the first k elements initially.
It reduces the number of unnecessary heap operations after the first k elements.
Conclusion:
Approach 2 is both better and easier to understand and implement. It maintains a max heap of size k from the start, ensuring that the top of the heap is always the k-th smallest element. This makes the code simpler and more efficient, as it mi
*/
