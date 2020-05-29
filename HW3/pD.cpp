#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <math.h>
using namespace std;
int main() {
	int n, cs = 1;
	while ( cin >> n && n ) {
		vector<int> arr(n);
		for ( int i=0; i<n; ++i )	cin >> arr[i];
		int avg = accumulate(arr.begin(),arr.end(),0)/n;
		cout << "Set #" << cs++ << "\nThe minimum number of moves is ";
		cout << accumulate(arr.begin(),arr.end(),0,[=](int x, int y){
			return x+max(0,avg-y);
		}) << ".\n\n";
	}
	return 0;
}
/*
6
5 2 4 1 7 5
0

*/