#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, l, r;
	string s;
	while ( cin >> n && n ) {
		getline(cin,s);
		getline(cin,s);
		if ( s[4] == 'h' ) {
			r = n;
			l = 0;
		} else if ( s[4] == 'l' ) {
			l = n;
			r = 11;
		} else {
			cout << "Stan may be honest\n";
			continue;
		}
		bool flag = true;
		while ( cin >> n ) {
			getline(cin,s);
			getline(cin,s);
			// cout << "l,r: " << l << ' ' << r << '\n';
			if ( s[4] == 'h' ) {
				if ( n <= l || n == 1 ) {
					flag = false;
				} else {
					r = min(r,n);
				}
			} else if ( s[4] == 'l' ) {
				if ( n >= r || n == 10 ) {
					flag = false;
				} else {
					l = max(l,n);
				}
			} else {
				// cout << "***n,l,r: " << n << ' ' << l << ' ' << r << '\n';
				if ( n <= l || n >= r ) {
					flag = false;
				}
				break;
			}
		}
		if ( flag ) {
			cout << "Stan may be honest\n";
		} else {
			cout << "Stan is dishonest\n";
		}
	}
	return 0;
}