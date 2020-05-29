#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <math.h>
using namespace std;
int main() {
	int n;
	while ( cin >> n ) {
		if ( n == 1 ) {
			cin >> n;
			cout << "Jolly\n";
			continue;
		}
		vector<int> arr(n), diff(n);

		for ( int i=0; i<n; ++i )	cin >> arr[i];

		adjacent_difference(arr.begin(),arr.end(),diff.begin(),[](int x, int y){ return abs(x-y); });

		vector<bool> used(n-1, 0);
		for ( int i=1; i<n; ++i ) {
			if ( 1 <= diff[i] && diff[i] < n )
				used[diff[i]-1] = true;
		}

		if ( all_of(used.begin(), used.end(), [](int x){ return x; }) )
			cout << "Jolly\n";
		else
			cout << "Not jolly\n";
	}
	return 0;
}
/*
4 1 4 2 3
5 1 4 2 -1 6

*/