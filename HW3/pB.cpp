#include <iostream>
#include <vector>
#include <numeric>
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
		double bound = (double)accumulate(arr.begin(),arr.end(),0)/(double)n;
		int cnt = count_if(arr.begin(),arr.end(),[=](int x){ return x > bound; });
		printf("%.3lf%\n", double(cnt)/double(n)*100);
	}
	return 0;
}
/*
5
5 50 50 70 80 100
7 100 95 90 80 70 60 50
3 70 90 80
3 70 90 81
9 100 99 98 97 96 95 94 93 91

*/