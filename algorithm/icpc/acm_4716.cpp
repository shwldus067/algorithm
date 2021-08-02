#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
struct str{
	int k, da, db;
	bool operator<(const str& T)const{
		return abs(db-da)>abs(T.db-T.da);
	}
};
int main(){
	int N, A, B;
	str team[1001];
	while(scanf("%d %d %d", &N, &A, &B), N){
		for(int i=0;i<N;++i)	scanf("%d %d %d", &team[i].k, &team[i].da, &team[i].db);
		sort(team, team+N);
		int ans=0;
		for(int i=0;i<N;++i){
			int k=team[i].k, da=team[i].da, db=team[i].db;
			if(da<db){
				if(A>=k)	ans+=k*da, A-=k;
				else{
					ans+=A*da;
					ans+=(k-A)*db, B-=k-A, A=0;
				}
			}
			else{
				if(B>=k)	ans+=k*db, B-=k;
				else{
					ans+=B*db;
					ans+=(k-B)*da, A-=k-B, B=0;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
