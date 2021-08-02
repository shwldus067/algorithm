#include<iostream>
#include<vector>
#include<math.h>
#include<stack>
using namespace std;
struct cdn{
	int r, c;
};
int N, M, res=10000;
vector<cdn> home;
vector<cdn> chicken;
bool visit[14];
stack<int> S;

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

void dfs(){
	int cnt=1, s_n=0;
	S.push(s_n);
	while(!S.empty()){
		s_n=S.top();
		visit[s_n]=true;
		if(s_n+M-cnt>=chicken.size()){
			S.pop();
			visit[s_n]=false;
			cnt--;
			if(cnt){
				s_n=S.top();
				visit[s_n]=false;
				S.pop();
				S.push(s_n+1);
			}
			continue;
		}
		if(cnt==M){
			cal();
			S.pop();
			cnt--;
			visit[s_n]=false;
			if(cnt){
				if(s_n+1==chicken.size()){
					s_n=S.top();
					S.pop();
					cnt--;
					visit[s_n]=false;
				}
			}
			S.push(s_n+1);
			cnt++;
			continue;
		}
		S.push(s_n+1);
		cnt++;
	}
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
	dfs();
	cout<<res;
	return 0;
}
