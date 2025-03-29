#include <iostream>
using namespace std;

void loang(int **O, bool **flag, int i, int j, int m, int n) {
    flag[i][j] = true;
    
    if (j > 0 && O[i][j - 1] == O[i][j] && !flag[i][j - 1]) 
        loang(O, flag, i, j - 1, m, n);
    
    if (i > 0 && O[i - 1][j] == O[i][j] && !flag[i - 1][j]) 
        loang(O, flag, i - 1, j, m, n);
    
    if (j < n - 1 && O[i][j + 1] == O[i][j] && !flag[i][j + 1]) 
        loang(O, flag, i, j + 1, m, n);
    
    if (i < m - 1 && O[i + 1][j] == O[i][j] && !flag[i + 1][j]) 
        loang(O, flag, i + 1, j, m, n);
}

int countConnectedRegions(int **O, int m, int n) {
    bool **flag = new bool*[m];
    for (int i = 0; i < m; i++) {
        flag[i] = new bool[n];
        for (int j = 0; j < n; j++) {
            flag[i][j] = false;
        }
    }

    int regionCount = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!flag[i][j]) {
                regionCount++;
                loang(O, flag, i, j, m, n);
            }
        }
    }

    for (int i = 0; i < m; i++) {
        delete[] flag[i];
    }
    delete[] flag;
    return regionCount;
}

int main() {
    int m = 5, n = 5; 
    int **O = new int*[m];
    
    int data[5][5] = {
        {1, 1, 0, 0, 0},
        {1, 1, 0, 1, 1},
        {0, 0, 1, 1, 1},
        {0, 1, 1, 0, 0},
        {1, 1, 0, 0, 1}
    };

    for (int i = 0; i < m; i++) {
        O[i] = new int[n];
        for (int j = 0; j < n; j++) {
            O[i][j] = data[i][j];
        }
    }

    int regions = countConnectedRegions(O, m, n);
    cout << "So mien lien thong: " << regions << endl;

    for (int i = 0; i < m; i++) {
        delete[] O[i];
    }
    delete[] O;

    return 0;
}

