#include <iostream>
using namespace std;

int n = 4;
int x[6] = {1, 2, 3, 4, 5, 6};
bool dd[7] = {false};

void show() {
    for (int i = 0; i < n; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
}

void Try(int k) {
    for (int i = 1; i <= n; i++) {
        if (!dd[i]) {
            x[k] = i;
            if (k == n - 1) {
                show();
            } else {
                dd[i] = true;
                Try(k + 1);
                dd[i] = false;
            }
        }
    }
}

int main() {
    Try(0);
    return 0;
}

