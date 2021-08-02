#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int N;
vector<pii> point;
vector<int> ch;
int ccw(pii a, pii b, pii c){
	int x1=b.first-a.first, x2=c.first-a.first;
	int y1=b.second-a.second, y2=c.second-a.second;
	ll ret=1ll*x1*y2-1ll*y1*x2;
	if(ret>0)	return 1;
	else if(ret==0)	return 0;
	else	return -1;
}
bool cmp(pii &a, pii &b){
	int ret=ccw(point[0], a, b);
	if(ret==0){
		if(a.first==b.first)	return a.second<b.second;
		return a.first<b.first;
	}
	else return ret==1;
}
void graham_scan(){
	ch.push_back(0);
	ch.push_back(1);
	for(int i=2;i<N;i++){
		while(ch.size()>=2){
			int p2=ch.back();
			ch.pop_back();
			int p1=ch.back();
			if(ccw(point[p1], point[p2], point[i])==1){
				ch.push_back(p2);
				break;
			}
		}
		ch.push_back(i);
	}
}
int main(){
	scanf("%d", &N);
	for(int i=0;i<N;i++){
		int x, y;
		scanf("%d %d", &x, &y);
		point.push_back({x, y});
	}
	swap(point[0], *min_element(point.begin(), point.end()));
	sort(point.begin()+1, point.end(), cmp);
	graham_scan();
	printf("%d\n", ch.size());
	return 0;
}
