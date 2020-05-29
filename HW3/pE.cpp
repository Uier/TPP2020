#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int n;
	string s;
	while ( cin >> n && n && cin >> s ) {
		int len = s.size()/n;
		for ( int i=0; i<n; ++i )
			reverse(s.begin()+i*len,s.begin()+(i+1)*len);
		cout << s << '\n';
	}	
	return 0;
}
/*
3 ABCEHSHSH
5 FA0ETASINAHGRI0NATWON0QA0NARI0
0

*/