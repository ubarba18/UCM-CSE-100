#include <iostream>
using namespace std;
 
void MaxHeapify(int arr[], int num, int i){
   
    int largest = i; //index of "largeset" assume
    int l = 2*i+1; //Left child of index
    int r = 2*i + 2; //right child of index
 
    //Find the largest out of the 3
    if (l < num && arr[l] > arr[largest]) { //compares to left child
        largest = l; 
    }
    else {
        largest = i;
    }
    if (r < num && arr[r] > arr[largest]){ //compares to right child
        largest = r;
    }
 
   
    if (largest != i) { //if right or left is larger
        int temp = arr[i];
        arr[i] = arr[largest]; //Swap
        arr[largest] = temp;
        MaxHeapify(arr, num, largest); //double check if childrens children may be larger
    }
 
}
 
void BuildMaxHeap(int arr[], int num) {
    int parent = num/2; //last parent node: bottom row would have no children no need to maxheapify and above should be largest
    for (int i = parent-1; i >= 0; i--) { //from last parent node to root
        MaxHeapify(arr, num, i); //used to preserve the max heap property
    }
}
 
void HeapSort(int arr[], int heapsize) {
    BuildMaxHeap(arr, heapsize); //Call to Build Max Heap
 
    //[6,5,4,1,3,2]
 
    for (int i = heapsize-1; i >= 0; i--) { //start from last to root
        int temp = arr[i]; //
        arr[i] = arr[0]; //swap last with root - root is holding largest value of heap
        arr[0] = temp; //as we iterate we ignore index N - 1[2,5,4,1,3,2,|6], [2,3,4,1,|5,6], [1,3,2,|4,5,6], [2,1,3,4,5,6], [1,2,3,4,5,6]     
        MaxHeapify(arr, i, 0); //maxheapify new root, after maxheapify [5,3,4,1,2], [4,3,2,1], [3,1,2], [2,1] 
    }
    //heap is empty, array is sorted
}
 
 
 
int main() {
    int num = 0;
    cin >> num;
 
    int arr[num];
 
    for (int i = 0;i < num; i++) {
        cin >> arr[i];
    }
 
    HeapSort(arr, num);
 
    //print
    for (int i = 0; i < num; i++) {
        cout << arr[i]  << ";";
    }
    return 0;
}
 
 
 
 

