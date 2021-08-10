#include<iostream>
#include<vector>
using namespace std;
typedef pair<int, int> pii;
int cnt, arr[9][9];
vector<pii> emp;
int sol(int k){
	if(k==cnt)	return -1;
	int r=emp[k].first, c=emp[k].second;
	bool chk[10]={0, };
	for(int i=0;i<9;++i){
		if(arr[r][i])	chk[arr[r][i]]=1;
		if(arr[i][c])	chk[arr[i][c]]=1;
	}
	int nr=r/3*3, nc=c/3*3;
	for(int i=0;i<3;++i)for(int j=0;j<3;++j){
		if(arr[nr+i][nc+j])	chk[arr[nr+i][nc+j]]=1;
	}
	for(int i=1;i<10;++i){
		if(!chk[i]){
			arr[r][c]=i;
			if(sol(k+1)==-1)	return -1;
			arr[r][c]=0;
		}
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for(int i=0;i<9;++i)for(int j=0;j<9;++j){
		cin>>arr[i][j];
		if(arr[i][j]==0)	emp.push_back({i, j}), cnt++;
	}
	sol(0);
	for(int i=0;i<9;++i){
		for(int j=0;j<9;++j)	cout<<arr[i][j]<<" ";
		cout<<"\n";
	}
	return 0;
}
