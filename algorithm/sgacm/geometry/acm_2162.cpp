#include<iostream>
#include<vector>
using namespace std;
typedef pair<int, int> pii;
int N, parent[3000], r[3000], gnum, mseg;
pair<pair<int, int>, pair<int, int> > seg[3000];
int ccw(pii a, pii b, pii c){
	int x1, y1, x2, y2;
	x1=b.first-a.first, y1=b.second-a.second;
	x2=c.first-a.first, y2=c.second-a.second;
	int ret=x1*y2-x2*y1;
	if(ret>0)	return 1;
	else if(ret==0)	return 0;
	else	return -1;
}
bool group(int a, int b){
	pii f1=seg[a].first;
	pii s1=seg[a].second;
	pii f2=seg[b].first;
	pii s2=seg[b].second;
	int p=ccw(f1, s1, f2)*ccw(f1, s1, s2);
	int q=ccw(f2, s2, f1)*ccw(f2, s2, s1);
	if(p==0 && q==0){
		if(f1>s1)	swap(f1, s1);
		if(f2>s2)	swap(f2, s2);
		return f1<=s2 && f2<=s1;
	}
	return p<=0 && q<=0;
}
int find(int u){
	while(parent[u]!=u){
		u=parent[u];
	}
	return u;
}
void merge(int u, int v){
	u=find(u), v=find(v);
	if(u==v)	return;
	if(r[u]<r[v]){
		parent[u]=v;
		r[v]+=r[u];
	}
	else{
		parent[v]=u;
		r[u]+=r[v];
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	int x1, y1, x2, y2;
	for(int i=0;i<N;i++){
		cin>>x1>>y1>>x2>>y2;
		seg[i]={{x1, y1}, {x2, y2}};
		parent[i]=i;
		r[i]=1;
	}
	for(int i=0;i<N;i++){
		for(int j=i+1;j<N;j++){
			if(group(i, j)){
				merge(i, j);
			}
		}
	}
	for(int i=0;i<N;i++){
		if(parent[i]==i){
			gnum++;
			mseg=max(mseg, r[i]);
		}
	}
	cout<<gnum<<"\n"<<mseg<<"\n";
	return 0;
}
