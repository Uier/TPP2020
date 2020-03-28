#include <bits/stdc++.h>
#define maxn 5005
using namespace std;
int dp[maxn][maxn];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	string s, t;
	while ( cin >> n >> s >> m >> t ) {
		for ( int i=0; i<=n; ++i ) {
			dp[i][0] = i;
		}
		for ( int i=0; i<=m; ++i ) {
			dp[0][i] = i;
		}
		for ( int i=1; i<=n; ++i ) {
			for ( int j=1; j<=m; ++j ) {
				if ( s[i-1] == t[j-1] ) {
					dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1],min(dp[i-1][j-1],dp[i-1][j]))+1);
				} else {
					dp[i][j] = min(dp[i][j-1],min(dp[i-1][j-1],dp[i-1][j]))+1;
				}
				// cout << dp[i][j] << '\t';
			}
			// cout << '\n';
		}
		cout << dp[n][m] << '\n';
	}
	return 0;
}