#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int t;
	cin >> t;
	for ( int cs=1; cs<=t; ++cs ) {
		int n;
		cin >> n;
		vector<int> arr(n);
		for ( int i=0; i<n; ++i )	cin >> arr[i];
		cout << "Case " << cs << ": " << *max_element(arr.begin(),arr.end()) << '\n';
	}
	return 0;
}
/*
2
5 9 3 5 2 6
1 2

*/