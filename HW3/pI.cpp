#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	string s, t;
	while ( cin >> s >> t ) {
		int len = s.size();
		bool flag = true;
		for ( int i=0; i<len; ++i ) {
			string x = s.substr(i,1);
			auto found = t.find(x);
			if ( found != string::npos ) {
				t = t.substr(found+1,t.size()-found);
			}
			else {
				flag = false;
				break;
			}
		}
		if ( flag )
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	return 0;
}
/*
sequence subsequence
person compression
VERDI vivaVittorioEmanueleReDiItalia
caseDoesMatter CaseDoesMatter

*/