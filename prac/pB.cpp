#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int dp[maxn];
inline void check(int x) {
	int y = x, s = 0;
	while ( y ) {
		s += y%10;
		y /= 10;
	}
	dp[x] = x+s;
}
inline int len(int x) {
	int y = x, s = 0;
	while ( y ) {
		s++;
		y /= 10;
	}
	return s;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for ( int i=1; i<100000; ++i ) {
		check(i);
	}
	int t, n;
	cin >> t;
	while ( t-- && cin >> n ) {
		int l = len(n);
		l *= 9;
		int ans = 0;
		for ( int i=max(0,n-l); i<n; i++ ) {
			// cout << "i,dp[i]: " << i << ' ' << dp[i] << '\n';
			if ( dp[i] == n ) {
				ans = i;
				break;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}