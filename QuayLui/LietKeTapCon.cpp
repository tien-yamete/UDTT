#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> x;

void show() {
    cout << "{";
    for (int i = 0; i < m; ++i) {
        cout << x[i];
        if (i < m - 1) cout << ", ";
    }
    cout << "}" << endl;
}

void Try(int k) {
    int last_element = (k == 1) ? 0 : x[k-2]; 
    for (int i = last_element + 1; i <= n; ++i) {
        x[k-1] = i; 
        if (k == m) {
            show();
        } else {
            Try(k + 1);
        }
    }
}

int main() {
    cin >> n >> m;
    x.resize(m);
    Try(1); 
    return 0;
}

