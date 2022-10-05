#include <iostream>
using namespace std;



int main (int argc, char **argv){
    int arrSize = 0;
    int* Sequence;
    int temp, i,j,k;

    cin >> arrSize;
    Sequence = new int[arrSize];

    for (i = 0; i < arrSize; i++) { //store inputs
        cin >> Sequence[i];
    }

    //Sort
    for (i = 1; i < arrSize; i++){
        temp = Sequence[i];
        j = i - 1;
            while ((j >= 0) && (Sequence[j] > temp)){
                Sequence[j + 1] = Sequence[j];
                j = j - 1;
            }
            Sequence[j + 1] = temp; 
	// for (i = 1; i < arrSize; i++){
    //     temp = Sequence[i];
	// 	j = i; 
	// 		while ((j >= 0) && (Sequence[j] > temp)){ 
	// 			Sequence[j] = Sequence[j-1];
    //             j = j - 1; //
	// 			}
	// 		Sequence[j] = temp;

        //Print after each sort
        for (k = 0; k <= i; k++) { 
            cout << Sequence[k] << ";";
        }
        cout << endl;
    }

    delete[] Sequence;

    return 0;
}


    
            
