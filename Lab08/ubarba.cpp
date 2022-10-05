#include <iostream>
#include <climits>

using namespace std;

void printOptimalParens(int **s, int i, int  j){
    if (i == j){
        cout << "A" << i-1;
    }
    else {
        cout << "(";
        printOptimalParens(s, i, s[i][j]);
        printOptimalParens(s, s[i][j]+1, j);
        cout << ")";
    }

}

void matrixChainOrder(int *p, int n) {
    int **m = new int *[n]; //stores order in which we solve the parenthesization problem on matrix-chains of increasing length
    int **s = new int *[n]; //store index of optimal cost of computing

    for (int i = 0; i < n; i++){
        m[i] = new int[n]; 
        s[i] = new int[n];
    }

    for (int i = 0; i < n; i++){
        m[i][i] = 0;
    }

    for (int l = 2; l < n; l++) { //l is the chain length
		for (int i = 1; i < n - l + 1; i++){
            int j = i + l - 1;
            m[i][j] = INT_MAX; //infinity to calculute minimum value
            for(int k = i; k <= j - 1; k++){
                    int q = m[i][k] + m[k + 1][j] + (p[i - 1]*p[k]*p[j]);
                    if (q < m[i][j]){
                        m[i][j] = q;
                        s[i][j] = k;
                    }
            }
        }
    }

    cout << m[1][n-1] << endl;
    printOptimalParens(s, 1, n-1); //matrix # start at 0 and end at n-1
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    
    n++;
    int* p = new int [n];

    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    matrixChainOrder(p, n);
}