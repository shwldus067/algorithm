#include<iostream>
#include<algorithm>
using namespace std;
int N, M, D, arr[16][15], ans, enemy;
bool chk[15]={1, 1, 1, };
void sol(){
	int k=0, tmp[15][15]={0, }, sum=0, a[3];
	bool en[3]={0, 0, 0};
	pair<int, int> enm[3];
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			tmp[i][j]=arr[i][j];
		}
	}
	for(int j=0;j<M;++j){
		if(chk[j])	a[k++]=j;
	}
	for(int r=N;r>0;--r){
		for(int d=0;d<D;++d){
			int nr=r, c=-d-1;
			if(en[0] && en[1] && en[2])	break;
			for(int i=0;i<d*2+1;++i){
				if(en[0] && en[1] && en[2])	break;
				if(i<=d)	nr--;
				else	++nr;
				++c;
				for(int k=0;k<3;++k){
					if(en[k])	continue;
					int nc=c+a[k];
					if(nr<0 || nc<0 || nc>=M)	continue;
					if(tmp[nr][nc]){
						en[k]=1;
						enm[k]={nr, nc};
					}
				}
			}
		}
		for(int i=0;i<3;++i){
			if(en[i] && tmp[enm[i].first][enm[i].second])
				tmp[enm[i].first][enm[i].second]=0, ++sum;
			en[i]=0;
		}
		if(sum==enemy){
			ans=sum; return;
		}
	}
	if(ans<sum)	ans=sum;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M>>D;
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			cin>>arr[i][j];
			if(arr[i][j])	++enemy;
		}
	}
	do{
		sol();
		if(ans==enemy)	break;
	}while(prev_permutation(chk, chk+M));
	cout<<ans<<"\n";
	return 0;
}
