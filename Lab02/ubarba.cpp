#include <iostream>
using namespace std;

void Merge(int Sequence[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    int i, j, k;

    //Create Left and Right Arrays
    int leftArr[n1]; 
    int rightArr[n2];

    //Copy left side of Array
    for (i = 0; i < n1; i++) {
        leftArr[i] = Sequence[p+ i];
    }
 
    //Copy Right side pf Array
    for (j = 0; j < n2; j++) {
        rightArr[j] = Sequence[q+j+1];
    }


    i = 0, j = 0;

    //Sub-array Empty, copy smallest elements from left and right
    for (k = p; i < n1 && j < n2; k++) {
        if (leftArr[i] < rightArr[j]) {
            Sequence[k] = leftArr[i];
            i++;
        }
        else {
            Sequence[k] = rightArr[j];
            j++;
        }
    }

    //Merge all of left, incase subarrays have different elements
    while (i < n1) {
		Sequence[k] = leftArr[i]; 
        i++; 
        k++; 
    }

    //Merge all of right
    while (j < n2) { 
        Sequence[k] = rightArr[j]; 
        j++; 
        k++; 
	}
}

void mergeSort(int Sequence[], int p, int r) {
    int q;
    if (p < r) {
        q = (p+r)/2; //middle
        mergeSort(Sequence, p, q);
        mergeSort(Sequence, q + 1, r);
        Merge(Sequence, p, q, r);
    }
    
}
 

int main (){
    int arrSize = 0;
    int i;
 
    cin >> arrSize;
    int Sequence[arrSize];
 
    for (i = 0; i < arrSize; i++) { //store inputs
        cin >> Sequence[i];
    }
 
    //Sort
    mergeSort(Sequence, 0, arrSize - 1);

    //Print after each sort
    //     for (i = 0; i <= i; i++) {
    //         cout << Sequence[i] << ";";
    //     }
    //     cout << endl;  
    // }
    for(int i = 0; i < arrSize; i++){
        cout << Sequence[i] << ";";
    }
    
    return 0;
}
 
 
   
           
 

