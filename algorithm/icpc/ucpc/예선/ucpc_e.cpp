#include<iostream>
#include<algorithm>
using namespace std;
int N, Q, S;
int ro[1000001], ri=0;
int po[1000001], pi=0;
/*
void sol(){
	bool visit[N]={0, };
	int x=S, p=0, d=1, r=0, t=0;
	while(x>=0 && x<N){
		x=x+d;
		++t;
		if(str[x]=='P' && !visit[x]){
			visit[x]=true;
			++p, d=(d==1?-1:1);
		}
		else if(str[x]=='R'){
			++r, d=(d==1?-1:1);
			if(r==2){
				cout<<p<<"-1\n";
				return;
			}
		}
	}
	cout<<p<<' '<<t<<"\n";
	return;
}*/
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>Q;
	char tmp;
	int idx=0, time=0, potato, rock;
	for(int i=1;i<=N;++i){
		cin>>tmp;
		if(tmp=='P'){
			po[pi++]=i;
		}
		else if(tmp=='R'){
			ro[ri++]=i;
		}
	}
	while(Q--){
		cin>>S;
		potato=(int)(lower_bound(po, po+pi, S)-po);
		rock=(int)(lower_bound(ro, ro+ri, S)-ro);
		if(rock==ri && potato==pi){
			cout<<"0 "<<N-S+1<<"\n";
			continue;
		}
		//sol();
	}
	return 0;
}
