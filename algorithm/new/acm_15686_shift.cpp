#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
struct cdn{
	int r, c;
};
int N, M, res=10000;
vector<cdn> home;
vector<cdn> chicken;
bool visit[14];

void cal(){
	int tmp, r_tmp=0;
	for(int i=0;i<home.size();i++){
		int dis=100;
		for(int j=0;j<chicken.size();j++){
			if(visit[j]){
				tmp=abs(home[i].r-chicken[j].r)+abs(home[i].c-chicken[j].c);
				if(tmp<dis)	dis=tmp;
			}
		}
		r_tmp+=dis;
	}
	if(r_tmp<res)	res=r_tmp;
}

int main(){
	int tmp;
	cin>>N>>M;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin>>tmp;
			if(tmp==1){
				home.push_back({i, j});
			}
			else if(tmp==2){
				visit[chicken.size()]=false;
				chicken.push_back({i, j});
			}
		}
	}
		
	for(int i=1;i<(1<<chicken.size());i++){
		int cnt=0;
		fill(visit, visit+chicken.size(), false);
		for(int j=0;j<chicken.size();j++){
			if(i&(1<<j)){
				cnt++;
				visit[j]=true;
			}
		}
		if(cnt!=M){
			continue;
		}
		cal();
	}
	
	cout<<res;
	return 0;
}
