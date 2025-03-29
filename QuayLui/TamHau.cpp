#include <iostream>
#include <cstdlib> 
using namespace std;

const int N = 8;
int queens[N];    
int dem = 0;     

bool isValid(int row, int col) {
    for (int i = 0; i < row; ++i) {
        if (queens[i] == col || abs(i - row) == abs(queens[i] - col)) {
            return false;
        }
    }
    return true;
}

void inGiaiPhap() {
    cout << "Giai phap " << dem << ":\n";

    cout << "Vi tri cac quan hau:\n";
    for (int i = 0; i < N; ++i) {
        cout << "(" << i << ", " << queens[i] << ") ";//in vtri
    }
    cout << "\n\n";

    cout << "Ban co:\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << (queens[i] == j ? "Q " : ". ");
        }
        cout << endl;
    }
    cout << "\n------------------------\n\n";
}

void datHau(int row) {
    if (row == N) {
        dem++; 
        inGiaiPhap(); 
        return;
    }

    for (int col = 0; col < N; ++col) {
        if (isValid(row, col)) {
            queens[row] = col;  
            datHau(row + 1);     
            queens[row] = -1;    
        }
    }
}

int main() {
    for (int i = 0; i < N; ++i) {
        queens[i] = -1;
    }

    datHau(0); 
    cout << "Tong so giai phap cho ban co " << N << "x" << N << ": " << dem;
    return 0;
}
