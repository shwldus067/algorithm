#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, M, done[1000000];
struct query{
	int t, a, b;
};
query q[1000000];
struct fwtree{
	int n;
	vector<int> tree;
	fwtree():n(0){}
	explicit fwtree(const vector<bool> &a){
		n=a.size();
		tree=vector<int>(n+1, 0);
		for(int i=0;i<n;i++){
			if(a[i])	update(i+1);
		}
	}
	int query(int i){
		int res=0;
		while(i>0){
			res+=tree[i];
			i-=(i&-i);
		}
		return res;
	}
	void update(int i){
		while(i<=n){
			tree[i]++;
			i+=(i&-i);
		}
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
	vector<bool> v(occur.size());
	int i=0, j=0;
	while(i<N && j<occur.size()){
		if(done[i]==occur[j])	v[j]=true, i++, j++;
		else if(done[i]<occur[j])	i++;
		else	j++;
	}
	fwtree fw(v);
	for(int i=0;i<M;i++){
		int op=q[i].t;
		if(op==1){
			int a=lower_bound(occur.begin(), occur.end(), q[i].a)-occur.begin();
			fw.update(a+1);
		}
		else{
			int a=lower_bound(occur.begin(), occur.end(), q[i].a)-occur.begin();
			int b=lower_bound(occur.begin(), occur.end(), q[i].b)-occur.begin();
			int c=fw.query(b+1)-fw.query(a);
			cout<<(q[i].b-q[i].a+1)-c<<"\n";
		}
	}
	return 0;
}
