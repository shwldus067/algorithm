#include<iostream>
#include<queue>
using namespace std;
int main(){
	int F, S, G, U, D, tmp, cnt;
	queue<pair<int, int> > Q;
	cin>>F>>S>>G>>U>>D;
	bool visit[F+1]={false, };
	visit[S]=true;
	Q.push({S, -1});
	while(!Q.empty()){
		tmp=Q.front().first;
		cnt=Q.front().second;
		Q.pop();
		cnt++;
		if(tmp==G){
			cout<<cnt<<"\n";
			return 0;
		}
		if(tmp+U<=F && visit[tmp+U]==false){
			Q.push({tmp+U, cnt});
			visit[tmp+U]=true;
		}
		if(tmp-D>0 && visit[tmp-D]==false){
			Q.push({tmp-D, cnt});
			visit[tmp-D]=true;
		}
	}
	cout<<"use the stairs\n";
	return 0;
} 
