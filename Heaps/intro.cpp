// Insertion,deletion ,heapify,heapsort 
#include <iostream>
#include<queue>
using namespace std;

class heap {
    public:
        int arr[100];
        int size;

        heap() {
            arr[0] = -1;
            size = 0;
        }

        void insert(int val) {
            size = size + 1;
            int index = size;
            arr[index] = val;  // Corrected: Use the input value 'val' instead of 'size'

            while (index > 1) {
                int parent = index / 2;

                if (arr[parent] < arr[index]) {
                    swap(arr[parent], arr[index]);
                    index = parent;
                } else {
                    return;
                }
            }
        }
        void deleteFromHeap()
        {
        if (size == 0)
        {
            cout << "nothing to delete" << endl;
            return;
        }

        // put last node element at root node
        arr[1] = arr[size];

        // remove lase node
        size--;

        // put root node at corect position
        int i = 1;

        while (i < size)
        {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;

            if (leftIndex < size && arr[i] < arr[leftIndex] && arr[leftIndex] > arr[rightIndex])
            {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }

            else if (rightIndex < size && arr[i] < arr[rightIndex] && arr[leftIndex] < arr[rightIndex])
            {
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }

            else
            {
                return;
            }
        }
    }
        void print() {
            for (int i = 1; i <= size; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

// for 0 based indexing 
/*
void heapify(int arr[],int size,int i){
    int largest=i;
    int left= 2*i;
    int right=2*i+1;

    // 
    if(left < size && arr[largest]<arr[left]){
        largest = left; // replace the largest with left
    }
    if(right < size && arr[largest] < arr[right]){
        largest = right;
    }*/

// for 1 base indexing 
void heapify(int arr[],int size,int i){
    int largest=i;
    int left= 2*i;
    int right=2*i+1;

    // 
    if(left <= size && arr[largest]<arr[left]){
        largest = left; // replace the largest with left
    }
    if(right <= size && arr[largest] < arr[right]){
        largest = right;
    }

//  if replaced 
    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,size,largest);
    }
}
void heapSort(int arr[],int size){
    int heapsize=size;
    // step 1: 
    while(heapsize > 1){
        swap(arr[1],arr[heapsize]);

        // step 2:
        heapsize--;

        // step 3:
        heapify(arr,heapsize,1);
    }
}
int main() {
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();

    int arr[6]={-1, 54, 53 , 55, 52, 50};
    int n=5;

    // heap creation
    for(int i=n/2; i>0; i--){
        heapify(arr, n, i);
    }

    cout<<"printing the array now"<<endl;
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }cout<< endl;

    // heap Sort
    heapSort(arr, n);
    cout<<"printing the Sorted Array"<<endl;
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }cout<< endl;

    cout<<"Using Priority Queue here"<<endl;
    // maxHeap
    priority_queue<int> pq;
    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);

    cout<<"Element at top"<<pq.top()<<endl;
    pq.pop();
    cout<<"Size is:"<<pq.size()<<endl;

    if(pq.empty()){
        cout<<"pq is empty"<<endl;
    }
    else{
        cout<<"pq is not empty"<<endl;
    }


    // MINHEAP
    priority_queue<int,vector<int>,greater<int> >minHeap;
    minHeap.push(4);
    minHeap.push(2);
    minHeap.push(5);
    minHeap.push(3);
    cout<<"Element at top"<<minHeap.top()<<endl;
    minHeap.pop();
    cout<<"Size is:"<<minHeap.size()<<endl;

    if(minHeap.empty()){
        cout<<"min Heap is empty"<<endl;
    }
    else{
        cout<<" minHeap is not empty"<<endl;
    }


    return 0;
}
