#include<iostream>
#include<queue>
using namespace std;
int N, K;
bool visit[500001][2];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>K;
	if(N==K){
		cout<<"0\n";
		return 0;
	}
	queue<int> Q;
	Q.push(N);
	int size, cur, next, cnt=1, ch;
	visit[N][0]=true;
	while(size=Q.size()){
		K+=cnt;
		if(K>500000){
			cout<<"-1\n";
			return 0;
		}
		ch=cnt&1;
		if(visit[K][ch]){
			cout<<cnt<<"\n";
			return 0;
		}
		while(size--){
			cur=Q.front();
			Q.pop();
			next=cur-1;
			if(next>=0){
				if(next==K){
					cout<<cnt<<"\n";
					return 0;
				}
				else if(!visit[next][ch]){
					visit[next][ch]=true;
					Q.push(next);
				}
			}
			next=cur+1;
			if(next<=500000){
				if(next==K){
					cout<<cnt<<"\n";
					return 0;
				}
				else if(!visit[next][ch]){
					visit[next][ch]=true;
					Q.push(next);
				}
			}
			next=cur<<1;
			if(next<=500000){
				if(next==K){
					cout<<cnt<<"\n";
					return 0;
				}
				else if(!visit[next][ch]){
					visit[next][ch]=true;
					Q.push(next);
				}
			}
		}
		cnt++;
	}
	cout<<"-1\n";
	return 0;
}
