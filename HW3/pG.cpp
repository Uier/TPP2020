#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int n, q, cs = 1;
	while ( cin >> n >> q && (n||q) ) {
		vector<int> arr(n);
		for ( int i=0; i<n; ++i )	cin >> arr[i];
		sort(arr.begin(), arr.end());
		cout << "CASE# " << cs++ << ":\n";
		int x;
		while ( q-- && cin >> x ) {
			int pos = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
			if ( pos < n && arr[pos] == x )
				cout << x << " found at " << pos+1 << '\n';
			else	cout << x << " not found\n";
		}
	}
	return 0;
}
/*
4 1
2
3
5
1
5
5 2
1
3
3
3
1
2
3
0 0

*/