#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int arr[maxn], brr[maxn];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	while ( cin >> n >> m && (n||m) ) {
		for ( int i=0; i<n; ++i ) {
			cin >> arr[i];
		}
		for ( int i=0; i<m; ++i ) {
			cin >> brr[i];
		}
		int cnt1 = 0, cnt2 = 0;
		for ( int i=0; i<n; ++i ) {
			if ( i > 0 && arr[i] == arr[i-1] )	continue;
			int pos = lower_bound(brr,brr+m,arr[i])-brr;
			if ( pos < m && brr[pos] == arr[i] ) {
				continue;
			}
			cnt1++;
		}
		for ( int i=0; i<m; ++i ) {
			if ( i > 0 && brr[i] == brr[i-1] )	continue;
			int pos = lower_bound(arr,arr+n,brr[i])-arr;
			if ( pos < n && arr[pos] == brr[i] ) {
				continue;
			}
			cnt2++;	
		}
		cout << min(cnt1,cnt2) << '\n';
	}
	return 0;
}