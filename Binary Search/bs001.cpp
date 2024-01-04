// Implementation of binary search 
#include<iostream>
using namespace std;
int binary_search(int arr[],int size,int key){
    int beg=0;
    int end=size-1;
    int mid;
    while(beg<=end){
        mid=beg+((end-beg)/2);
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]>key){
            beg=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return -1;
}
int main(){
    int arr[5]={4,8,18,22,34};
    int key;
    cout<<"Enter the value to search";
    cin>>key;
    int ans=binary_search(arr,5,key);
    cout<<ans;
    return 0;
}
