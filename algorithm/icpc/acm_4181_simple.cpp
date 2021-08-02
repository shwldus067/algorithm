#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int N, pdx, idx, ch[100000];
pii point[100000];
ll ccw(pii &a, pii &b, pii &c){
	return 1ll*(b.first-a.first)*(c.second-a.second)-1ll*(b.second-a.second)*(c.first-a.first);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;++i){
		int x, y;
		cin>>x>>y;
		char c;
		cin>>c;
		if(c=='Y')	point[pdx++]={x, y};
	}
	sort(point, point+pdx);
	vector<int> upper, lower;
	for(int i=0;i<pdx;++i){
		while(idx>=2){
			if(ccw(point[ch[idx-2]], point[ch[idx-1]], point[i])<0)	idx--;
			else break;
		}
		ch[idx++]=i;
	}
	lower.insert(lower.end(), ch, ch+idx);
	idx=0;
	for(int i=0;i<pdx;++i){
		while(idx>=2){
			if(ccw(point[ch[idx-2]], point[ch[idx-1]], point[i])>0)	idx--;
			else break;
		}
		ch[idx++]=i;
	}
	upper.insert(upper.end(), ch+1, ch+idx-1);
	reverse(upper.begin(), upper.end());
	lower.insert(lower.end(), upper.begin(), upper.end());
	cout<<lower.size()<<"\n";
	for(int i:lower)
		cout<<point[i].first<<" "<<point[i].second<<"\n";
	return 0;
}
