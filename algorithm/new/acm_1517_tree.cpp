#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
int n, a[500555];
vector<int> tree;
 
ll query(ll i) {
    ll ret = 0;
    while (i > 0)    ret += tree[i], i -= (i & -i);
    return ret;
}
 
void update(ll i) {
    while (i <= n)    tree[i]++, i += (i & -i);
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
    ll ret = 0;
    cin>>n;
    for (ll i = 1; i <= n; i++)    cin>>a[i], tree.push_back(a[i]);
    sort(tree.begin(), tree.end());
    tree.erase(unique(tree.begin(), tree.end()), tree.end());
    for (ll i = 1; i <= n; i++)        a[i] = lower_bound(tree.begin(), tree.end(), a[i]) - tree.begin() + 2;
    tree.resize(500555);
    for (ll i = 0; i < 500555; i++)    tree[i] = 0;
    for(ll i=n;i>=1;i--)    ret += query(a[i] - 1), update(a[i]);
    cout<<ret<<"\n";
}
