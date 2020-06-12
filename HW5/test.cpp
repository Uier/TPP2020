#include <iostream>
#include "string.h"
using namespace std;
int main() {
	String a, b, c;
	c = "123";
	cin >> a >> b;
	c += (a+b);
	cin >> a >> b;
	cout << (c+b) << '\n';
	return 0;
}