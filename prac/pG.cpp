#include <bits/stdc++.h>
using namespace std;
struct node {
	int a, b, c;
};
bool operator <(const node& x, const node& y) {
	return tie(x.a,x.b,x.c) < tie(y.a,y.b,y.c);
}
int check(node d, int ed) {
	int ans = 0;
	if ( d.a <= ed )	ans = max(ans,d.a);
	if ( d.b <= ed )	ans = max(ans,d.b);
	if ( d.c <= ed )	ans = max(ans,d.c);
	return ans;
}
int ansans, ansdist;
void bfs(int a, int b, int c, int ed) {
	map<node,int> D;
	queue<node> Q;
	node st = {0,0,c};
	D[st] = 1;
	Q.push(st);
	ansans = check(st,ed);
	ansdist = 1;
	while ( !Q.empty() ) {
		// cout << "Q.sz: " << Q.size() << '\n';
		node tmp = Q.front();	Q.pop();
		// cout << "tmp.abc: " << tmp.a << ' ' << tmp.b << ' ' << tmp.c << '\n';
		int cur = D[tmp], diff = 0;
		// cout << "cur: " << cur << '\n';
		node d;
		// a -> b
		diff = tmp.a;
		d.a = max(0,tmp.b+tmp.a-b);
		d.b = min(b,tmp.b+tmp.a);
		d.c = tmp.c;
		diff -= d.a;
		if ( D[d] == 0 || cur+diff < D[d] ) {
			if ( check(d,ed) > ansans ) {
				ansans = check(d,ed);
				ansdist = cur+diff;
			} else if ( check(d,ed) == ansans ) {
				ansdist = min(ansdist,cur+diff);
			}
			D[d] = cur+diff;
			Q.push(d);
		}
		// b -> a
		diff = tmp.b;
		d.a = min(a,tmp.b+tmp.a);
		d.b = max(0,tmp.b+tmp.a-a);
		d.c = tmp.c;
		diff -= d.b;
		if ( D[d] == 0 || cur+diff < D[d] ) {
			if ( check(d,ed) > ansans ) {
				ansans = check(d,ed);
				ansdist = cur+diff;
			} else if ( check(d,ed) == ansans ) {
				ansdist = min(ansdist,cur+diff);
			}
			D[d] = cur+diff;
			Q.push(d);
		}
		// a -> c
		diff = tmp.a;
		d.a = max(0,tmp.c+tmp.a-c);
		d.b = tmp.b;
		d.c = min(c,tmp.c+tmp.a);
		diff -= d.a;
		if ( D[d] == 0 || cur+diff < D[d] ) {
			if ( check(d,ed) > ansans ) {
				ansans = check(d,ed);
				ansdist = cur+diff;
			} else if ( check(d,ed) == ansans ) {
				ansdist = min(ansdist,cur+diff);
			}
			D[d] = cur+diff;
			Q.push(d);
		}
		// c -> a
		diff = tmp.c;
		d.a = min(a,tmp.c+tmp.a);
		d.b = tmp.b;
		d.c = max(0,tmp.c+tmp.a-a);
		diff -= d.c;
		if ( D[d] == 0 || cur+diff < D[d] ) {
			if ( check(d,ed) > ansans ) {
				ansans = check(d,ed);
				ansdist = cur+diff;
			} else if ( check(d,ed) == ansans ) {
				ansdist = min(ansdist,cur+diff);
			}
			D[d] = cur+diff;
			Q.push(d);
		}
		// b -> c
		diff = tmp.b;
		d.a = tmp.a;
		d.b = max(0,tmp.c+tmp.b-c);
		d.c = min(c,tmp.c+tmp.b);
		diff -= d.b;
		if ( D[d] == 0 || cur+diff < D[d] ) {
			if ( check(d,ed) > ansans ) {
				ansans = check(d,ed);
				ansdist = cur+diff;
			} else if ( check(d,ed) == ansans ) {
				ansdist = min(ansdist,cur+diff);
			}
			D[d] = cur+diff;
			Q.push(d);
		}
		// c -> b
		diff = tmp.c;
		d.a = tmp.a;
		d.b = min(b,tmp.c+tmp.b);
		d.c = max(0,tmp.c+tmp.b-b);
		diff -= d.c;
		if ( D[d] == 0 || cur+diff < D[d] ) {
			if ( check(d,ed) > ansans ) {
				ansans = check(d,ed);
				ansdist = cur+diff;
			} else if ( check(d,ed) == ansans ) {
				ansdist = min(ansdist,cur+diff);
			}
			D[d] = cur+diff;
			Q.push(d);
		}
		// if ( ansans == ed ) {
			// break;
		// }
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t, a, b, c, d;
	cin >> t;
	while ( t-- && cin >> a >> b >> c >> d ) {
		bfs(a,b,c,d);
		cout << ansdist-1 << ' ' << ansans << '\n';
	}
	return 0;
}