#include<iostream>
#include<queue>
#include<string>
#include<set>
using namespace std;
int dr[]={-1, 0, 1, 0}, dc[]={0, -1, 0, 1};
char arr[3][3];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int s=0, t;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cin>>t;
			if(t==0)	t=9;
			s=s*10+t;
		}
	}
	if(s==123456789){
		cout<<"0\n";
		return 0;
	}
	queue<int> Q;
	set<int> v;
	Q.push(s);
	v.insert(s);
	int cnt=1, size;
	while(size=Q.size()){
		while(size--){
			int cur=Q.front();
			Q.pop();
			string str=to_string(cur);
			int x=str.find("9");
			int c=x%3, r=x/3;
			for(int i=0;i<4;i++){
				string next=str;
				int nr=r+dr[i], nc=c+dc[i];
				if(nr<0 || nr>2 || nc<0 || nc>2)	continue;
				int nx=nr*3+nc;
				int tp=next[x];
				next[x]=next[nx];
				next[nx]=tp;
				int num=stoi(next);
				if(num==123456789){
					cout<<cnt<<"\n";
					return 0;
				}
				set<int>::iterator iter;
				iter=v.find(num);
				if(iter==v.end()){
					v.insert(num);
					Q.push(num);
				}
			}
		}
		cnt++;
	}
	cout<<"-1\n";
	return 0;
}
