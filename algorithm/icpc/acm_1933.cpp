#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int N;
struct bd{
	int lx, h, rx;
	bool operator<(bd &a){
		if(lx==a.lx){
			if(rx==a.rx)	return h>a.h;
			return rx<a.rx;
		}
		return lx<a.lx;
	}
}arr[100000];
struct cmp{
	bool operator()(int a, int b){
		return arr[a].h<arr[b].h;
	}
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;++i){
		int l, h, r;
		cin>>l>>h>>r;
		arr[i]={l, h, r};
	}
	sort(arr, arr+N);
	priority_queue<int, vector<int>, cmp> pq;
	int cur=0;
	cout<<arr[0].lx<<" "<<arr[0].h<<" ";
	pq.push(0);
	for(int i=1;i<N;++i){
		if(arr[cur].rx<arr[i].lx){
			int t;
			while(pq.size() && arr[t=pq.top()].rx<=arr[cur].rx)
				pq.pop();
			if(pq.size()){
				if(arr[cur].h>arr[t].h){
					cout<<arr[cur].rx<<" "<<arr[t].h<<" ";
				}
				cur=t;
				if(arr[t].h<arr[i].h){
					cout<<arr[i].lx<<" "<<arr[i].h<<" ";
					cur=i;
				}
			}
			else{
				cout<<arr[cur].rx<<" "<<0<<" ";
				cout<<arr[i].lx<<" "<<arr[i].h<<" ";
				cur=i;
			}
		}
		else{
			if(arr[cur].h<arr[i].h){
				cout<<arr[i].lx<<" "<<arr[i].h<<" ";
				cur=i;
			}
			else if(arr[cur].h==arr[i].h && arr[cur].rx<=arr[i].rx){
				cur=i;
				pq.pop();
			}
		}
		pq.push(i);
	}
	while(1){
		int t;
		while(pq.size() && arr[t=pq.top()].rx<=arr[cur].rx)
			pq.pop();
		if(pq.empty())	break;
		if(arr[cur].h>arr[t].h)
			cout<<arr[cur].rx<<" "<<arr[t].h<<" ";
		cur=t;
	}
	cout<<arr[cur].rx<<" "<<0<<" ";
	return 0;
}
