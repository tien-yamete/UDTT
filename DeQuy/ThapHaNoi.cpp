#include <iostream>
using namespace std;

void towerOfHanoi(int n, char a, char b, char c) {
    if (n == 1) {
        cout << "Di chuyen dia 1 tu " << a << " sang " << c << endl;
        return;
    }
    towerOfHanoi(n - 1, a, c, b); 
    cout << "Di chuyen dia " << n << " tu " << a << " sang " << c << endl; 
    towerOfHanoi(n - 1, b, a, c); 
}

int main() {
    int n;
    cout << "Nhap so luong dia: ";
    cin >> n;
    towerOfHanoi(n, 'A', 'B', 'C'); 
    return 0;
}

