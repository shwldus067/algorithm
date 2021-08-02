#include<iostream>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;
pii p[1000000], r[250000];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, cnt=0, f=0;
	int s=0, i, idx=0, ans1=0, ans2=0, b=2e9;
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>p[i].first>>p[i].second;
		if(p[i].second<0 && p[i].first<b){
			s=i, b=p[i].first;
		}
	}
	p[N]=p[0];
	for(i=s;i<N;++i){
		if(p[i].first==p[i+1].first){
			if(p[i].second<0 && p[i+1].second>0){
				r[idx].first=p[i].first;
			}
			else if(p[i].second>0 && p[i+1].second<0){
				if(r[idx].first>p[i].first){
					r[idx].second=r[idx].first;
					r[idx++].first=p[i].first;
				}
				else	r[idx++].second=p[i].first;
			}
		}
	}
	for(i=0;i<s;++i){
		if(p[i].first==p[i+1].first){
			if(p[i].second<0 && p[i+1].second>0){
				r[idx].first=p[i].first;
			}
			else if(p[i].second>0 && p[i+1].second<0){
				if(r[idx].first>p[i].first){
					r[idx].second=r[idx].first;
					r[idx++].first=p[i].first;
				}
				else	r[idx++].second=p[i].first;
			}
		}
	}
	sort(r, r+idx);
	pii pre={-2e9, -2e9};
	for(i=0;i<idx;++i){
		if(pre.second<r[i].first){
			pre=r[i];
			ans1++;
		}
	}
	pre={2e9, 2e9};
	for(int i=idx-1;i>=0;--i){
		if(pre.first>r[i].second){
			pre=r[i];
			ans2++;
		}
	}
	cout<<ans1<<" "<<ans2<<"\n";
	return 0;
}
