#include<iostream>
#include<algorithm>
using namespace std;
int r, c, k, A[100][100], R=3, C=3;
int B[101], idx;
pair<int, int> P[100];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>r>>c>>k;
	for(int i=0;i<3;++i)for(int j=0;j<3;++j)	cin>>A[i][j];
	int time=0;
	--r, --c;
	int ns;
	while(A[r][c]!=k && time<101){
		++time;
		ns=0;
		if(R>=C){
			for(int i=0;i<R;++i){
				for(int j=1;j<101;++j)	B[j]=0;
				for(int j=0;j<C;++j){
					B[A[i][j]]++;
				}
				idx=0;
				for(int j=1;j<101;++j){
					if(B[j])	P[idx++]={B[j], j};
				}
				sort(P, P+idx);
				ns=max(ns, idx*2);
				for(int j=0;j<idx && j<50;j++){
					A[i][j*2]=P[j].second, A[i][j*2+1]=P[j].first;
				}
				for(int j=idx*2;j<100;++j)	A[i][j]=0;
			}
			C=ns;
		}else{
			for(int i=0;i<C;++i){
				for(int j=1;j<101;++j)	B[j]=0;
				for(int j=0;j<C;++j){
					B[A[j][i]]++;
				}
				idx=0;
				for(int j=1;j<101;++j){
					if(B[j])	P[idx++]={B[j], j};
				}
				sort(P, P+idx);
				ns=max(ns, idx*2);
				for(int j=0;j<idx && j<50;j++){
					A[j*2][i]=P[j].second, A[j*2+1][i]=P[j].first;
				}
				for(int j=idx*2;j<100;++j)	A[j][i]=0;
			}
			R=ns;
		}
	}
	if(time>100)	cout<<"-1\n";
	else cout<<time<<"\n";
}
