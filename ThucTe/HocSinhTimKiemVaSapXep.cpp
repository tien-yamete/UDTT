#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct HocSinh{
	char hoDem[50];
	char ten[20];
	int namSinh;
	char diaChi[100];
};
void hienThi(HocSinh hs){
	cout<<hs.hoDem<<" "<<hs.ten<<setw(30)<<hs.namSinh<<setw(20)<<hs.diaChi<<endl;
}
void tieuDe(){
	cout<<"Ho Ten"<<setw(40)<<"Nam Sinh"<<setw(20)<<"Dia Chi"<<endl;
}

int partition(HocSinh ds[], int low, int high) {
    char *pivot = ds[high].ten;
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (strcmp(ds[j].ten, pivot) < 0) {
            i++;
            swap(ds[i], ds[j]);
        }
    }
    swap(ds[i + 1], ds[high]);
    return i + 1;
}

void quickSort(HocSinh ds[], int low, int high) {
    if (low < high) {
        int pi = partition(ds, low, high);
        quickSort(ds, low, pi - 1);
        quickSort(ds, pi + 1, high);
    }
}

int timTheoTen(HocSinh ds[], int n, char tenCanTim[]) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        int cmp = strcmp(ds[mid].ten, tenCanTim);
        if (cmp == 0) return mid;
        else if (cmp < 0) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}
void inDS(HocSinh ds[], int n){
	tieuDe();
    for(int i = 0; i<n; i++){
    	hienThi(ds[i]);
	}
}
int main(int argc, char** argv) {
	int n = 6;
    HocSinh ds[n] = {
        {"Nguyen Van", "An", 2005, "Ha Noi"},
        {"Tran Thi", "Binh", 2004, "Hai Phong"},
        {"Le Van", "Cuong", 2006, "Da Nang"},
        {"Pham Thi", "An", 2005, "Hue"},
        {"Doan Van", "Dung", 2003, "TP.HCM"},
        {"Hoang Thi", "Ha", 2005, "Can Tho"}
    };
    quickSort(ds, 0, n-1);
    cout<<"Danh sach sau khi da sap xep theo ten : "<<endl;
    inDS(ds, n);
    
	char tenCanTim[] = "An";
    int viTri = timTheoTen(ds, n, tenCanTim);
    if (viTri != -1) {
        cout << "\nTim thay hoc sinh co ten \"" << tenCanTim << "\" tai vi tri " << viTri << ":\n";
        hienThi(ds[viTri]);
    } else {
        cout << "\nKhong tim thay hoc sinh co ten \"" << tenCanTim << "\".\n";
    }
	return 0;
}
