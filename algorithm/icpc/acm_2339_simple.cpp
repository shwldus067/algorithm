#include<iostream>
using namespace std;
int N, arr[20][20];
int chk(int sr, int sc, int er, int ec, int dr, int dc){
	int cnt=0;
	while(sr<=er && sc<=ec){
		if(arr[sr][sc]==2)	return 0;
		if(arr[sr][sc]==1)	++cnt;
		sr+=dr;
		sc+=dc;
	}
	if(cnt==0)	return 0;
	return 1;
}
int cut(int sr, int sc, int er, int ec, int d){
	if(sr>er || sc>ec)	return 0;
	int jw=0, tr=0;
	for(int i=sr;i<=er;++i)
		for(int j=sc;j<=ec;++j){
			if(arr[i][j]==1)	++tr;
			else if(arr[i][j]==2)	++jw;
		}
	if(jw==1 && tr==0)	return 1;
	int ret=0;
	if(d==0){
		for(int i=sr;i<=er;++i){
			if(chk(i, sc, i, ec, 0, 1)==0)	continue;
			ret+=cut(sr, sc, i-1, ec, 1)*cut(i+1, sc, er, ec, 1);
		}
	}
	else{
		for(int i=sc;i<=ec;++i){
			if(chk(sr, i, er, i, 1, 0)==0)	continue;
			ret+=cut(sr, sc, er, i-1, 0)*cut(sr, i+1, er, ec, 0);
		}
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;++i)
		for(int j=0;j<N;++j)
			cin>>arr[i][j];
	int ans=cut(0, 0, N-1, N-1, 0)+cut(0, 0, N-1, N-1, 1);
	if(ans)	cout<<ans<<"\n";
	else	cout<<"-1\n";
	return 0;
}
