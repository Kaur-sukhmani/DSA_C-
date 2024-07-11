// Merge two binary Max heaps
// https://www.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1
/*Merge two binary Max heaps
Difficulty: EasyAccuracy: 58.65%Submissions: 44K+Points: 2
Given two binary max heaps as arrays, merge the given heaps to form a new max heap.

 

Example 1:

Input  : 
n = 4 m = 3
a[] = {10, 5, 6, 2}, 
b[] = {12, 7, 9}
Output : 
{12, 10, 9, 2, 5, 7, 6}
Explanation :




 

 

Your Task:  
You don't need to read input or print anything. Your task is to complete the function mergeHeaps() which takes the array a[], b[], its size n and m, as inputs and return the merged max heap. Since there can be multiple solutions, therefore, to check for the correctness of your solution, your answer will be checked by the driver code and will return 1 if it is correct, else it returns 0.

 

Expected Time Complexity: O(n.Logn)
Expected Auxiliary Space: O(n + m)

 

Constraints:
1 <= n, m <= 105
1 <= a[i], b[i] <= 2*105
*/
//{ Driver Code Starts
// Initial Template for C++

// C++ program to merge two max heaps.

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    // 1 base indexing ka hai yeah toh
    void heapify(vector<int> &arr, int size, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && arr[largest] < arr[left]) {
            largest = left;
        }
        if (right < size && arr[largest] < arr[right]) {
            largest = right;
        }

        if (largest != i) {
            swap(arr[largest], arr[i]);
            heapify(arr, size, largest);
        }
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
      vector<int> c;
        
        // Merging arrays a and b into c
        for (int i = 0; i < n; i++) {
            c.push_back(a[i]);
        }
        for (int i = 0; i < m; i++) {
            c.push_back(b[i]);
        }

        int size1 = c.size();
        for (int i = (size1 / 2) - 1; i >= 0; i--) {
            heapify(c, size1, i);
        }

        return c;
    }
};

//{ Driver Code Starts.

bool isMerged(vector<int> &arr1, vector<int> &arr2, vector<int> &merged){
    if (arr1.size() + arr2.size() != merged.size()){
        return false;
    }
    arr1.insert(arr1.end(),arr2.begin(),arr2.end());
    sort(arr1.begin(),arr1.end());
    vector<int> mergedCopy =merged;
    sort(mergedCopy.begin(),mergedCopy.end());
    if (arr1 != mergedCopy){
        return false;
    }
    for(int i = 1; i<merged.size(); i++){
        if(merged[i] > merged[(i-1)/2])
            return false;
    }
    return true;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, i;
        cin >> n >> m;
        vector<int> a(n,0),b(m,0);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (i = 0; i < m; i++) {
            cin >> b[i];
        }
        vector<int> merged, copyA = a, copyB = b;
        Solution obj;
        merged = obj.mergeHeaps(a, b, n, m);
        bool flag = isMerged(copyA, copyB, merged);
        if(flag == false) cout<<0<<endl;
        else cout<<1<<endl;
    }
    return 0;
}

// } Driver Code Ends
