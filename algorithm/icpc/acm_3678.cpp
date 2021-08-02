#include<iostream>
using namespace std;
int t, n, arr[300][300], cnt[6]={10000, }, res[10001];
int inp[200];
int dr[6]={1, 0, -1, -1, 0, 1}, dc[6]={1, 2, 1, -1, -2, -1};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	for(int i=0;i<t;++i)	cin>>inp[i];
	int r=150, c=150, d=0, cc=0, dd=0;
	arr[150][150]=res[1]=cnt[1]=1;
	for(int i=2;i<10001;++i){
		int k=0, chk[6]={0, };
		r+=dr[d], c+=dc[d];
		for(int j=0;j<7;++j){
			chk[arr[r+dr[j]][c+dc[j]]]=true;
		}
		for(int j=1;j<6;++j){
			if(chk[j])	continue;
			if(cnt[j]<cnt[k])	k=j;
		}
		res[i]=arr[r][c]=k;
		++cnt[k];
		if(cc<dd)	++cc;
		else	cc=0, ++d;
		if(d==1){
			if(cc==dd)	++d, cc=0;
		}
		else if(d==6){
			++dd, d=0;
		}
	}
	for(int i=0;i<t;++i){
		cout<<res[inp[i]]<<"\n";
	}
	return 0;
}
