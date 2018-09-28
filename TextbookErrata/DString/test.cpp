#include <iostream>

#include "DString.cpp"
using namespace std;

int main(){
	DString a;
	DString b("cde");
	cout << a << b << endl;
	DString c(b);
	cout << c << endl;
	
	a = b;
	cout << a << endl;
	a += b;
	cout << a << endl;
}
