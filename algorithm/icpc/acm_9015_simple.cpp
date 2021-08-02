#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<int, int> pii;
int T, N, arr[20001][2];
pii point[3000];
bool fun(int x, int y){
	if(x<0 || y<0 || x>20000 || y>20000 || arr[x][0]<0)
		return false;
	for(int i=arr[x][0];i<=arr[x][1];++i){
		if(y==point[i].second){
			return true;
		}
	}
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		cin>>N;
		for(int i=0;i<20001;++i)	arr[i][0]=arr[i][1]=-1;
		for(int i=0;i<N;++i){
			cin>>point[i].first>>point[i].second;
			point[i].first+=10000;
			point[i].second+=10000;
		}
		sort(point, point+N);
		for(int i=0;i<N;++i){
			if(arr[point[i].first][0]==-1){
				arr[point[i].first][0]=i;
				arr[point[i].first][1]=i;
			}
			else{
				arr[point[i].first][1]=i;
			}
		}
		int dx, dy, ans=0;
		for(int i=0;i<N;++i){
			for(int j=i+1;j<N;++j){
				dx=point[i].first-point[j].first;
				dy=point[i].second-point[j].second;
				if(dy<0){
					if(fun(point[j].first-dy, point[j].second+dx) && 
					fun(point[i].first-dy, point[i].second+dx)){
						ans=max(ans, dx*dx+dy*dy);
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
