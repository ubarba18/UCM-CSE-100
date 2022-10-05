#include <iostream>

using namespace std;

int findMaxCrossSubArray (int arr[], int low, int mid, int high) {
    int leftSum = -999999999;
    int sum = 0;
    for (int i = mid; i >= low; i--) {
        sum = sum + arr[i];
        if (sum > leftSum) {
            leftSum = sum;
        }
    }

    int rightSum = -999999999;
    sum = 0;
    for (int j = mid + 1; j <= high; j++) {
        sum = sum + arr[j];
        if (sum > rightSum) {
            rightSum = sum;
        }
    }
    return leftSum + rightSum;
}

int findMaxSubArray (int arr[], int low, int high) {
    // Base case return first
    if (high == low) {
        return arr[low]; 
    }
    //Check rest of the 3 cases
    else {
        int mid = (low + high)/2; 
        int leftSubSum = findMaxSubArray(arr, low, mid);
        int rightSubSum = findMaxSubArray(arr, mid + 1, high);
        int crossSum = findMaxCrossSubArray(arr, low, mid, high);

        //Return max
        if (leftSubSum >= rightSubSum && leftSubSum >= crossSum) {
            return leftSubSum;
        }

        else if (rightSubSum >= leftSubSum && rightSubSum >= crossSum) {
            return rightSubSum;
         }

        else {
            return crossSum;
        
        }
    }
}
int main () {
    int num = 0;
    int MAX = 0;

    cin >> num;
    int arr[num];

    for (int i = 0; i < num; i++) {
        cin >> arr[i];
    }

    MAX = findMaxSubArray(arr, 0 , num - 1);
    cout << MAX;

    return 0;
}