#include<iostream>
using namespace std;
int N, K, A[10][10], B[3][20];
int idx[3], cnt[3];
bool chk[10]={0, };
bool sol(int n, int p1, int p2){
	if(cnt[0]==K)	return true;
	if(cnt[1]==K || cnt[2]==K)	return false;
	int res;
	if(p1!=0){
		if(p2!=0){
			res=A[B[p1][idx[p1]]][B[p2][idx[p2]]];
			idx[p1]++;idx[p2]++;
			if(res==0){
				cnt[p2]++;
				if(sol(p1, 0, p2))	return true;
				cnt[p2]--;
			}else if(res==1){
				cnt[2]++;
				if(sol(1, 0, 2))	return true;
				cnt[2]--;
			}else{
				cnt[p1]++;
				if(sol(p2, 0, p1))	return true;
				cnt[p1]--;
			}
			idx[p1]--;idx[p2]--;
			return false;
		}else{
			p2=p1;p1=0;
		}
	}
	//p1:0 p2:other
	int h2=B[p2][idx[p2]];
	idx[p2]++;
	for(int i=1;i<=N;++i){
		if(chk[i])	continue;
		chk[i]=1;
		res=A[i][h2];
		if(res==0){
			cnt[p2]++;
			if(sol(0, p2, n))	return true;
			cnt[p2]--;
		}else if(res==1){
			cnt[p2]++;
			if(sol(0, p2, n))	return true;
			cnt[p2]--;
		}else{
			cnt[0]++;
			if(sol(p2, 0, n))	return true;
			cnt[0]--;
		}
		chk[i]=0;
	}
	idx[p2]--;
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int idx[3]={0, }, cnt[3]={0, };
	cin>>N>>K;
	for(int i=1;i<=N;++i)for(int j=1;j<=N;++j)	cin>>A[i][j];
	for(int i=0;i<20;++i)	cin>>B[1][i];
	for(int i=0;i<20;++i)	cin>>B[2][i];
	if(sol(2, 0, 1))	cout<<"1\n";
	else	cout<<"0\n";
	return 0;
}
