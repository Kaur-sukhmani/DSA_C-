// K-th Largest Sum Contiguous Subarray
// https://www.geeksforgeeks.org/problems/k-th-largest-sum-contiguous-subarray/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article
/*
Difficulty: MediumAccuracy: 54.33%Submissions: 18K+Points: 4
You are given an array Arr of size N. You have to find the K-th largest sum of contiguous subarray within the array elements. In other words, overall subarrays, find the subarray with kth largest sum and return its sum of elements.

 

Example 1:

Input:
N = 3
K = 2
Arr = {3,2,1}
Output:
5
Explanation:
The different subarray sums we can get from the array
are = {6,5,3,2,1}. Where 5 is the 2nd largest.
 

Example 2:

Input:
N = 4
K = 3
Arr = {2,6,4,1}
Output:
11
Explanation:
The different subarray sums we can get from the array
are = {13,12,11,10,8,6,5,4,2,1}. Where 11 is the 3rd largest.
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function kthLargest() which takes the array Arr[] and its size N as inputs and returns the Kth largest subarray sum.

 

Expected Time Complexity: O(N2 * log K)
Expected Auxiliary Space: O(K)

 

Constraints:
1 <= N <= 100
1 <= K <= (N*(N+1))/2
-105 <= Arr[i] <= 105
*/

// APPRAOCH 1-> BRUTE FORCE APPRAOCH 
class Solution{
public:
    // priority_queue<int,vector<int>, greator<int> >pq;//min heap
    int kthLargest(vector<int> &Arr,int N,int K){
        // int sum=0;
        vector<int> store_Sum;
        for(int i=0;i<N;i++){
            int sum=0;
            for(int j=i;j<N;j++){
                sum+=Arr[j];
                store_Sum.push_back(sum);
            }
        }
        sort(store_Sum.begin(),store_Sum.end());
        // for(int i=0;i<K;i++){
        //     store_Sum.pop();
        // }
        return store_Sum[store_Sum.size()-K];
    }
};

// TC=O(N^2 logN)
// Sc->O(N^2)

// Another Approach ->using heaps
int kthLargest(vector<int> &Arr,int N,int K){
        priority_queue<int,vector<int>, greater<int> >mini;
        for(int i=0;i<N;i++){
            int sum=0;
            for(int j=i;j<N;j++){
                sum+=Arr[j];
                if(mini.size()<K){
                    mini.push(sum);
                }
                else{
                    if(sum>mini.top()){
                        mini.pop();
                        mini.push(sum);
                    }
                }
            }
        }
        return mini.top();
    }
