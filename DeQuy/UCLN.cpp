#include <iostream>

int ucln(int a, int b){
	if(a %b ==0)
		return b;
	return ucln(b, a%b);
}
int ucln(int a, int b){
	int r = a%b;
	while (r !=0){
		a = b;
		b = r;
		r = a%b;
	}
	return b;
}
int main(int argc, char** argv) {
	return 0;
}
