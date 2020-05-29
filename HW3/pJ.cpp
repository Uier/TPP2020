#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <numeric>
using namespace std;
struct point {
	int x, y;
};
inline int f(int x) {
	int s = 1;
	for ( int i=2; i<=x; ++i )	s *= i;
	return s;
}
double dist(point u, point v) {
	double sq = (u.x-v.x)*(u.x-v.x)+(u.y-v.y)*(u.y-v.y);
	return sqrt(sq);
}
int main() {
	int n, cs = 1;
	while ( cin >> n && n ) {
		vector<point> arr(n);
		vector<int> permutation(n), ans(n);
		for ( int i=0; i<n; ++i )	cin >> arr[i].x >> arr[i].y;
		iota(permutation.begin(), permutation.end(), 0);
		int cnt = f(n);
		double mn = -1;
		for ( int i=0; i<cnt; ++i ) {
			double sum = 0;
			for ( int i=0; i<n-1; ++i )
				sum += dist(arr[permutation[i]],arr[permutation[i+1]]);
			if ( mn == -1 || sum < mn ) {
				copy(permutation.begin(), permutation.end(), ans.begin());
				mn = sum;
			}
			if ( i != cnt-1 )
				next_permutation(permutation.begin(), permutation.end());
		}
		cout << "**********************************************************\n";
		cout << "Network #" << cs++ << '\n';
		double sum = 0;
		for ( int i=0; i<n-1; ++i ) {
			point u = arr[ans[i]], v = arr[ans[i+1]];
			printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n", 
				u.x,
				u.y,
				v.x,
				v.y,
				dist(u,v)+16
			);
			sum += dist(u,v)+16;
		}
		printf("Number of feet of cable required is %.2lf.\n", sum);

	}
	return 0;
}
/*
6
5 19
55 28
38 101
28 62
111 84
43 116
5
11 27
84 99
142 81
88 30
95 38
3
132 73
49 86
72 111
0

*/