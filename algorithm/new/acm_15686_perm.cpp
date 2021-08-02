#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
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
		
	for(int i=0;i<M;i++){
		visit[i]=true;
	}
	
	do{
		cal();
	}while(prev_permutation(visit, &visit[chicken.size()]));
	
	cout<<res;
	return 0;
}
