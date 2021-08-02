#include <iostream>
#include <iomanip>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <map>
#include <queue>
#include <vector>
#include <set>
#include <string>
#include <stack>
//#include <unordered_map>
//#include <unordered_set>

using namespace std;

typedef long long ll;
typedef double db;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
//typedef tuple<int, int, int> tiii;
//typedef tuple<ll, ll, ll> tlll;

#define mod7        1000000007
#define mod9        1000000009

#define forall(v)   v.begin(), v.end()
#define prec(x)     setprecision(x) << fixed

int tree[500001];
int n;

int sum(int i) {
	int s = 0;
	while (i > 0) {
		s += tree[i];
		i -= (i & -i);
	}
	return s;
}

void update(int i, int d) {
	while (i <= n) {
		tree[i] += d;
		i += (i & -i);
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	
	cin >> n;

	vector<pii> a(n), b(n); // id, idx
	vector<int> c(n);
		cin >> b[i].first;

	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}

	for (int i = 0; i < n; i++) {
		b[i].second = i;
	}

	sort(forall(a));
	sort(forall(b));

	ll s = 0;
	for (int i = 0; i < n; i++) {
		c[a[i].second] = b[i].second;
	}

	for (int i = 0; i < n; i++) {
		update(c[i] + 1, 1);
		s += i + 1 - sum(c[i] + 1);
	}

	cout << s;

	return 0;
}
