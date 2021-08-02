#include<iostream>
using namespace std;
typedef pair<int, int> pii;
int N, K, L, sdx;
int dr[4]={0, 1, 0, -1}, dc[4]={1, 0, -1, 0};
bool apple[100][100], snake[100][100];
pii turn[100], spoint[10200];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>K;
	for(int i=0;i<K;++i){
		int a, b;
		cin>>a>>b;
		apple[a-1][b-1]=1;
	}
	cin>>L;
	for(int i=0;i<L;++i){
		int a;
		char b;
		cin>>a>>b;
		if(b=='L')	turn[i]={a, 0};
		else	turn[i]={a, 1};
	}
	int hr=0, hc=0, time=0, d=0, idx=0, len=1;
	while(1){
		snake[hr][hc]=true;
		spoint[sdx++]={hr, hc};
		hr+=dr[d], hc+=dc[d];
		if(hr<0 || hr>=N || hc<0 || hc>=N)	break;
		if(snake[hr][hc])	break;
		if(apple[hr][hc])	apple[hr][hc]=false, ++len;
		else{
			snake[spoint[sdx-len].first][spoint[sdx-len].second]=false;
		}
		++time;
		if(turn[idx].first==time){
			if(turn[idx].second)	d=d>2 ? 0:d+1;
			else	d=d==0 ? 3:d-1;
			++idx;
		}
	}
	cout<<time+1<<"\n";
	return 0;
}
