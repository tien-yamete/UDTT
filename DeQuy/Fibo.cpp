#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<long> dp(100, -1);

long fibo(int n){
	if(n<3)
		return 1;
	// if(n<=1) return n;
	return fibo(n-1) + fibo(n-2);
}

long fibo2(int n) {
    if (n <= 1) return n; 
    if (dp[n] != -1) return dp[n]; 
    return dp[n] = fibo2(n - 1) + fibo2(n - 2); 
}

long fibo1(int n){
	long t1= 1, t2 = 1, tn;
	for(int i = 3; i<=n; i++){
		tn = t1+t2;
		t2 = t1;
		t1=tn;
	}
	return tn;
}
int main(int argc, char** argv) {
	int n;
	cin>>n;
	cout<<fibo2(n);
	return 0;
}
