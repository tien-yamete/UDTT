#include <iostream>
#include <iomanip>
using namespace std;

const int N = 8; 
int banCo[N][N];  

int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

void khoiTaoBanCo() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            banCo[i][j] = -1;
        }
    }
}

bool isValid(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && banCo[x][y] == -1);
}

bool diChuyen(int x, int y, int buoc) {
    banCo[x][y] = buoc; 

    if (buoc == N * N - 1) {
        return true;
    }

    for (int i = 0; i < 8; ++i) {
        int newX = x + dx[i];
        int newY = y + dy[i];
        
        if (isValid(newX, newY)) {
            if (diChuyen(newX, newY, buoc + 1)) {
                return true;
            }
        }
    }

    banCo[x][y] = -1;
    return false;
}

void inBanCo() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << setw(3) << banCo[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    khoiTaoBanCo(); 
    
    int startX = 0, startY = 0; 
    banCo[startX][startY] = 0;  
    
    if (diChuyen(startX, startY, 0)) {
        cout << "Loi giai tim duoc:" << endl;
        inBanCo();
    } else {
        cout << "Khong tim thay loi giai!" << endl;
    }
    
    return 0;
}
