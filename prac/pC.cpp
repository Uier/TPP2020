#include <bits/stdc++.h>
using namespace std;
map<string,int> M;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	string s;
	cin >> n;
	for ( int i=0; i<n; ++i ) {
		cin >> s;
		M[s]++;
		getline(cin,s);
	}
	for ( auto i=M.begin(); i!=M.end(); i++ ) {
		cout << i->first << ' ' << i->second << '\n';
	}
	return 0;
}