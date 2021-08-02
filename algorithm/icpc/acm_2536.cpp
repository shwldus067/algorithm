#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct bus{
	int x1, y1, x2, y2;
}B[5001];
bool visit[5001];
vector<int> h[100001], v[100001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int M, N, K, sx, sy, dx, dy, b, x1, y1, x2, y2, sz, ans=0;
	cin>>M>>N>>K;
	for(int i=0;i<K;++i){
		cin>>b>>x1>>y1>>x2>>y2;
		if(x1==x2){
			if(y1>y2)	swap(y1, y2);
			v[x1].push_back(b);
		}
		else{
			if(x1>x2)	swap(x1, x2);
			h[y1].push_back(b);
		}
		B[b]={x1, y1, x2, y2};
	}
	cin>>sx>>sy>>dx>>dy;
	queue<int> Q;
	for(int n:h[sy]){
		if(sx>=B[n].x1 && sx<=B[n].x2){
			visit[n]=1;Q.push(n);
		}
	}
	for(int n:v[sx]){
		if(sy>=B[n].y1 && sy<=B[n].y2){
			visit[n]=1;Q.push(n);
		}
	}
	while(sz=Q.size()){
		++ans;
		while(sz--){
			int cur=Q.front();Q.pop();
			x1=B[cur].x1, y1=B[cur].y1;
			x2=B[cur].x2, y2=B[cur].y2;
			if(y1==y2){
				if(y1==dy && dx>=x1 && dx<=x2){
					cout<<ans<<"\n";return 0;
				}
				for(int x=x1;x<=x2;++x){
					for(int n:v[x]){
						if(!visit[n] && y1>=B[n].y1 && y1<=B[n].y2){
							visit[n]=1;Q.push(n);
						}
					}
				}
				for(int n:h[y1]){
					if(!visit[n] && x1<=B[n].x2 && x2>=B[n].x1){
						visit[n]=1;Q.push(n);
					}
				}
			}
			else{
				if(x1==dx && dy>=y1 && dy<=y2){
					cout<<ans<<"\n";return 0;
				}
				for(int y=y1;y<=y2;++y){
					for(int n:h[y]){
						if(!visit[n] && x1>=B[n].x1 && x1<=B[n].x2){
							visit[n]=1;Q.push(n);
						}
					}
				}
				for(int n:v[x1]){
					if(!visit[n] && y1<=B[n].y2 && y2>=B[n].y1){
						visit[n]=1;Q.push(n);
					}
				}
			}
		}
	}
	return 0;
}
