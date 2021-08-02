#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, M, done[1000000];
struct query{
	int t, a, b;
};
query q[1000000];
struct segtree{
	int n;
	vector<int> tree;
	void init(int x, int s, int e, const vector<int> &a){
		if(s==e){
			tree[x]=a[s];
			return;
		}
		init(x<<1, s, (s+e)/2, a);
		init((x<<1)+1, (s+e)/2+1, e, a);
		tree[x]=tree[x<<1]+tree[(x<<1)+1];
	}
	segtree():n(0){}
	explicit segtree(const vector<int> &a){
		n=a.size();
		int x=1;
		while(x<a.size())	x<<=1;
		x<<=1;
		tree=vector<int>(x, 0);
		init(1, 0, n-1, a);
	}
	int _query(int x, int s, int e, int l, int r){
		if(r<s || e<l)	return 0;
		if(l<=s && e<=r)	return tree[x];
		return _query(x<<1, s, (s+e)/2, l, r)+_query((x<<1)+1, (s+e)/2+1, e, l, r);
	}
	int query(int l, int r){
		return _query(1, 0, n-1, l, r);
	}
	void _update(int x, int s, int e, int i, int val){
		if(e<i || i<s)	return;
		if(s==i && e==i){
			tree[x]+=val;
			return;
		}
		_update(x<<1, s, (s+e)/2, i, val);
		_update((x<<1)+1, (s+e)/2+1, e, i, val);
		tree[x]=tree[x<<1]+tree[(x<<1)+1];
	}
	void update(int i, int val){
		_update(1, 0, n-1, i, val);
	}
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<int> occur;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>done[i];
		occur.push_back(done[i]);
	}
	cin>>M;
	for(int i=0;i<M;i++){
		cin>>q[i].t>>q[i].a;
		occur.push_back(q[i].a);
		if(q[i].t==2){
			cin>>q[i].b;
			occur.push_back(q[i].b);
		}
	}
	sort(occur.begin(), occur.end());
	occur.erase(unique(occur.begin(), occur.end()), occur.end());
	vector<int> v(occur.size());
	int i=0, j=0;
	while(i<N && j<occur.size()){
		if(done[i]==occur[j])	v[j]=1, i++, j++;
		else if(done[i]<occur[j])	i++;
		else	j++;
	}
	segtree st(v);
	for(int i=0;i<M;i++){
		int op=q[i].t;
		if(op==1){
			int a=lower_bound(occur.begin(), occur.end(), q[i].a)-occur.begin();
			st.update(a, 1);
		}
		else{
			int a=lower_bound(occur.begin(), occur.end(), q[i].a)-occur.begin();
			int b=lower_bound(occur.begin(), occur.end(), q[i].b)-occur.begin();
			cout<<(q[i].b-q[i].a+1)-st.query(a, b)<<"\n";
		}
	}
	return 0;
}
