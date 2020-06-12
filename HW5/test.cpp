#include <iostream>
#include "string.h"
using namespace std;
int main() {
	String a("CSIE"), b(a);
	b[1] = '\0';
	cout << a << ' ' << b << '\n';
	a += b;
	cout << a << '\n';
	a[2] = '\0';
	a += b;
	cout << a << '\n';
	return 0;
}