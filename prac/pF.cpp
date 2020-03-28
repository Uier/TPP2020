#include <bits/stdc++.h>
#define maxn 1005
#define maxm 25005
#define int long long
using namespace std;
struct edge {
	int u, v, cost;
} G[maxm];
int p[maxn];
int find(int x) {
	return (p[x]==x ? x : (p[x]=find(p[x])));
}
vector<int> ans;
bool cmp(edge x, edge y) {
	return x.cost < y.cost;
}
int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	while ( cin >> n >> m && (n||m) ) {
		memset(G,0,sizeof(G));
		ans.clear();
		for ( int i=0; i<m; ++i ) {
			cin >> G[i].u >> G[i].v >> G[i].cost;
		}
		sort(G,G+m,cmp);
		for ( int i=0; i<=n; ++i )	p[i] = i;
		for ( int i=0; i<m; ++i ) {
			int tu = find(G[i].u), tv = find(G[i].v);
			if ( tu != tv ) {
				p[tv] = tu;
			} else {
				ans.emplace_back(G[i].cost);
			}
		}
		int sz = ans.size();
		if ( sz == 0 ) {
			cout << "forest\n";
			continue;
		}
		for ( int i=0; i<sz-1; i++ ) {
			cout << ans[i] << ' ';
		}
		cout << ans[sz-1] << '\n';
	}
	return 0;
}