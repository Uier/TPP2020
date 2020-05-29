#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	cout << "Lumberjacks:\n";
	for ( int i=0; i<n; ++i ) {
		vector<int> arr(10);
		for ( int j=0; j<10; ++j )	cin >> arr[j];
		if ( is_sorted(arr.begin(), arr.end()) ) {
			cout << "Ordered\n";
		} else {
			reverse(arr.begin(), arr.end());
			if ( is_sorted(arr.begin(), arr.end()) )
				cout << "Ordered\n";
			else
				cout << "Unordered\n";
		}
	}
	return 0;
}
/*
3
13 25 39 40 55 62 68 77 88 95
88 62 77 20 40 10 99 56 45 36
91 78 61 59 54 49 43 33 26 18

*/