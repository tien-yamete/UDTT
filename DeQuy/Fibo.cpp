#include <iostream>

long fibo(int n){
	if(n<3)
		return 1;
	return fibo(n-1) + fibo(n-2);
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
	return 0;
}
