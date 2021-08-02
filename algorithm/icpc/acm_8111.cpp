#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int T, N;
void bfs(void){
	vector<int> prev(N, -1);
	vector<int> one(N, -1);
	vector<int> ch(N, -1);
	queue<int> Q;
	if(N==1){
		cout<<"1\n";
		return ;
	}
	Q.push(1);
	ch[1]=0;
	one[1]=1;
	while(Q.size()){
		int cur=Q.front();
		Q.pop();
		if(cur==0)	break;
		for(int i=0;i<2;i++){
			int next=(cur*10+i)%N;
			if(ch[next]==-1){
				ch[next]=ch[cur]+1;
				prev[next]=cur;
				one[next]=i;
				Q.push(next);
			}
		}
	}
	if(ch[0]==-1){
		cout<<"BRAK"<<"\n";
		return;
	}
	string ans="";
	for(int i=0;i!=-1;i=prev[i]){
		ans+=to_string(one[i]);
	}
	reverse(ans.begin(), ans.end());
	cout<<ans<<"\n";
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		cin>>N;
		bfs();
	}
	return 0;
}
