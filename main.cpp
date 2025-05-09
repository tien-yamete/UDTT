#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct dauSach{
	char tenDauSach[50];
	int soTap;
	int soCuon;
	long giaBia;
};
void inTieuDe(){
	cout<<setw(20)<<"Ten Dau Sach"<<setw(20)<<"So Tap"<<setw(20)<<"So Cuon"<<setw(20)<<"Gia Bia"<<endl;
}
void inDL(dauSach sach){
	cout<<setw(20)<<sach.tenDauSach<<setw(20)<<sach.soTap<<setw(20)<<sach.soCuon<<setw(20)<<sach.giaBia<<endl;
}
int a4(dauSach d[], int n, int i){
	if(i>=n){
		return 0;
	}
	return d[i].giaBia + a4(d, n, i+1);
}
int a5(dauSach d[], int l, int r){
	if(l>r)
		return 0;
	if(l == r){
		if(d[l].giaBia >= 10000)
			return 1;
		else 
			return 0;
	}
	int m = (l+r) /2;
	return a5(d, l, m) + a5(d, m+1, r);
}
bool flags[50] = {false};
dauSach phuongAn[50];

void in(int n){
	for(int i = 0; i<n; i++){
		dauSach ds = phuongAn[i];
		cout<<setw(15)<<ds.tenDauSach<<setw(8)<<ds.giaBia;
	}
	cout<<endl;
}

int a6(dauSach d[], int n, int k, int select){
	int soLuong = 0;
	for(int i = 0; i<n; i++){
		if(flags[i])
			continue;
		phuongAn[k] = d[i];
		flags[i] = true;
		if(k == select -1){
			in(select);
			soLuong +=1;
		}
		
		soLuong+= a6(d, n, k+1, select);
		flags[i] = false;
	}
	return soLuong;
}

dauSach phuongAn2[50];
bool flags2[50] = {false};
void in2(int n){
	for(int i = 0; i<n; i++){
		dauSach ds = phuongAn2[i];
		cout<<setw(15)<<ds.tenDauSach<<setw(8)<<ds.giaBia;
	}
	cout<<endl;
}


int Try(dauSach d[], int n, int vtDangChon, int bd, int select) {
	int soLuong = 0;
    for (int i = bd; i < n; i++) {
        if (flags2[i]) continue; 
        phuongAn2[vtDangChon] = d[i];
        
        flags2[i] = true;

        if (vtDangChon == select-1) { 
            in2(5);
            soLuong+=1;
        } else {
            soLuong +=Try(d, n, vtDangChon + 1, i + 1, select); 
        }

        flags2[i] = false; 
    }
    return soLuong;
}


int main(int argc, char** argv) {
	int n = 7;
	dauSach d[n] = {
		{"Tieng viet", 12, 2, 9000},
		{"Toan", 10, 5, 35000},
		{"Hinh hoc", 10, 6, 4000},
		{"Tieng anh", 20, 12, 100000},
		{"Lich su", 8, 2, 120000},
		{"Dia ly", 7, 1, 17000},
		{"Tin hoc", 10, 1, 5000},	
	};
	long tong = a4(d, n, 0);
	cout<<tong<<endl;
	int dem = a5(d, 0, n);
	cout<<dem<<endl;
	int dem1 = a6(d, n, 0, 5);
	cout<<dem1<<endl;
	int soLuong = Try(d, n,0, 0, 5);
	cout<<soLuong;
	return 0;
}
