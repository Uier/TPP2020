#include <iostream>
#include "string.h"
using namespace std;
int main() {
	String s;
	cout << s[0] << ' ' << s.c_str() << ' ' << s.size() << '\n';
	String a("CSIE"), b(a);
	b[1] = '\0';
	cout << a << ' ' << b << '\n';
	a += b;
	cout << a << '\n';
	a[2] = '\0';
	a += b;
	cout << a << '\n';
	cout << a.c_str() << '\n';
	return 0;
}