#include<iostream>
using namespace std;
int L, N;
long long ans;
int t[1001];
char dir[1001];
int dx[4]={0, 1, 0, -1};
int dy[4]={1, 0, -1, 0};
pair<int, int> pos[1005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>L>>N;
	for(int i=0;i<N;++i){
		cin>>t[i]>>dir[i];
	}
	int x=L, y=L, time=0, d=1;
	int M=2*L;
	t[N]=M+2;
	pos[0]={L, L};
	pos[1]={L, L};
	for(int i=0;i<=N;++i){
		x+=dx[d]*t[i], y+=dy[d]*t[i];
		int dmin=M+2, f=0;
		for(int j=0;j<i-1;++j){
			if(d==0){
				if(pos[j].second==pos[j+1].second && x<=max(pos[j].first, pos[j+1].first)
				&& x>=min(pos[j].first, pos[j+1].first) 
				&& y>=pos[j].second && pos[i+1].second<=pos[j].second){
					dmin=min(dmin, pos[j].second-pos[i+1].second);
					f=1;
				}
			}
			else if(d==1){
				if(pos[j].first==pos[j+1].first && y<=max(pos[j].second, pos[j+1].second)
				&& y>=min(pos[j].second, pos[j+1].second) 
				&& x>=pos[j].first && pos[i+1].first<=pos[j].first){
					dmin=min(dmin, pos[j].first-pos[i+1].first);
					f=1;
				}
			}
			else if(d==2){
				if(pos[j].second==pos[j+1].second && x<=max(pos[j].first, pos[j+1].first)
				&& x>=min(pos[j].first, pos[j+1].first) 
				&& y<=pos[j].second && pos[i+1].second>=pos[j].second){
					dmin=min(dmin, pos[i+1].second-pos[j].second);
					f=1;
				}
			}
			else{
				if(pos[j].first==pos[j+1].first && y<=max(pos[j].second, pos[j+1].second)
				&& y>=min(pos[j].second, pos[j+1].second) 
				&& x<=pos[j].first && pos[i+1].first>=pos[j].first){
					dmin=min(dmin, pos[i+1].first-pos[j].first);
					f=1;
				}
			}
		}
		if(f==1){
			ans+=dmin*1ll;
			cout<<ans<<"\n";
			return 0;
		}
		if(x<0 || x>M || y<0 || y>M){
			if(d==2 || d==3)
				ans+=1ll*(pos[i+1].first+1)*((dx[d]+2)%2)+1ll*(pos[i+1].second+1)*((dy[d]+2)%2);
			else
				ans+=1ll*(M-pos[i+1].first+1)*((dx[d]+2)%2)+1ll*(M-pos[i+1].second+1)*((dy[d]+2)%2);
			cout<<ans<<"\n";
			return 0;
		}
		if(dir[i]=='L')	d=(d+3)%4;
		else	d=(d+1)%4;
		pos[i+2]={x, y};
		ans+=1ll*(((dx[d]+2)%2)+((dy[d]+2)%2))*t[i];
	}
	return 0;
}
