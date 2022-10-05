#include <iostream>

using namespace std;

void cutRod(int p[], int n){
    int r[n+1];
    int s[n+1];
    r[0] = 0;

    for (int j = 1; j <= n; j++) {
        int q = 0;
        for (int i = 1; i <= j; i++) {
            if (q < p[i] + r[j - i]) {
                q = p[i] + r[j - i];
                s[j] = i;
            }
        }
        r[j] = q;
    }

    cout << r[n] << "\n"; //max revenue
    while (n > 0) {
        cout << s[n] << " ";
        n = n - s[n];
    }   
}

int main() {
    int length;
    cin >> length;

    int p[length + 1];
    p[0] = 0;

    for(int i = 1; i < length + 1; i++){
        cin >> p[i];
    }
    
  cutRod(p, length);
  cout << "-1\n";
    return 0;
}