#include<iostream>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;
#define f first
#define s second
pair<pii, int> a[100000];
int N, m;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	map<int, int> x;
	for(int i=0;i<N;++i){
		cin>>a[i].f.f>>a[i].s>>a[i].f.s;
		x[a[i].f.f]=x[a[i].f.s]=0;
	}
	vector<int> rx;
	for(auto i:x){
		x[i.f]=m++;
		rx.push_back(i.f);
	}
	sort(a, a+N);
	int now=0;
	priority_queue<pii> pq;
	for(int i=0, j=0;i<m;++i){
		while(j<N && x[a[j].f.f]<=i){
			pq.push({a[j].s, x[a[j].f.s]});
			j++;
		}
		int next=0;
		while(pq.size()){
			if(i<pq.top().s){
				next=pq.top().f;
				break;
			}
			pq.pop();
		}
		if(now!=next){
			now=next;
			cout<<rx[i]<<" "<<now<<" ";
		}
	}
	return 0;
}
