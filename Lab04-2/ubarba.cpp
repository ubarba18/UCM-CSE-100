#include <iostream>
#include <utility>
#include <stdlib.h>
#include <string>
using namespace std;
 
int Partition(int arr[], int p, int r) {
    int a = arr[r];
    int i = p - 1;
    for (int j = p; j < r; j++)
    {
        if (arr[j] <= a) //check if less than pivot
        {
            i++; //incrementing both i and j
        int temp = arr[i];
        arr[i] = arr[j]; //swap i and j moving, larger numbers up
        arr[j] = temp;
        }
    }
    int temp = arr[i+1];
        arr[i+1] = arr[r]; //swap pivot with number infront of i which is apart of the right
        arr[r] = temp;
    return i + 1; //returns location of pivot
}
 
int randomPartition(int arr[], int p, int r) {
    int a = rand() % (r - p) + p; //Chooses randomPivot from length of the array
        int temp = arr[r];
        arr[r] = arr[a]; //Swap randomPivot and r
        arr[a] = temp;
 
        return Partition(arr, p, r);
}
 
void randomizedQuickSort(int arr[], int p, int r) {
    if (p < r) {
        int q = randomPartition(arr, p, r); //q is position of pivot
        randomizedQuickSort(arr, p, q-1); //Want to get items from left that are less than pivot
        randomizedQuickSort(arr, q+1, r); //want to get items from right that are larger than pivot
    }
}
 
int main () {
    int num = 0;
    cin >> num;
 
    int arr[num];
    for (int i = 0; i < num; i++) {
        cin >> arr[i];
    }
 
    randomizedQuickSort(arr, 0, num-1);
 
    for (int i = 0; i < num; i++) {
        cout << arr[i] << ";";
    }
}  
 

