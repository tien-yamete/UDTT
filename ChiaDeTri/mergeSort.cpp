#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void merge(double a[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    double *L = new double[n1];
    double *R = new double[n2];

    for (int i = 0; i < n1; i++)
        L[i] = a[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = a[mid + 1 + j];

    int i = 0, j = 0, k = left;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            a[k++] = L[i++];
        else
            a[k++] = R[j++];
    }

    while (i < n1)
        a[k++] = L[i++];
    while (j < n2)
        a[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void mergeSort(double a[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);
        merge(a, left, mid, right);
    }
}

void hienThiMang(double a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << "  ";
    cout << endl;
}

int main() {
    const int n = 15;
    double a[n] = {3.1, 9.2, 1.5, 7.7, 4.4, 2.9, 6.3, 8.6, 5.0, 0.2, 10.1, 12.5, 11.3, 13.9, 2.2};

    cout << "Mang ban dau:\n";
    hienThiMang(a, n);

    mergeSort(a, 0, n - 1);

    cout << "\nMang sau khi sap xep tang dan:\n";
    hienThiMang(a, n);

    return 0;
}

