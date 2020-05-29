#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int t, n;
	cin >> t;
	while ( t-- && cin >> n ) {
		vector<int> arr(n);
		for ( int i=0; i<n; ++i )	cin >> arr[i];
		nth_element(arr.begin(), arr.begin()+n/2, arr.end());
		cout << accumulate(arr.begin(), arr.end(), 0, [=](int x, int y) {
			return x+abs(y-arr[n/2]);
		}) << '\n';

	}
	return 0;
}
/*
2
2 2 4
3 2 4 6

*/