#include<iostream>
#include<algorithm>
using namespace std;
const int inf=150000;
int N, a[15], d[1<<15];
int sol(int left, int right){
	if(right==(1<<N)-1)	return 0;
	int &ret=d[left];
	if(ret!=0)	return ret;
	ret=inf;
	int m1=-1, m2=-1, M1=-1, M2=-1, cnt=0, move=N;
	for(int i=0;i<N;++i){
		if(left&(1<<i)){
			++cnt;
			if(m1==-1)	m1=i;
			else if(m2==-1)	m2=i;
			M2=M1;
			M1=i;
		}
		else if(move==N){
			move=i;
		}
	}
	if(cnt==2){
		return ret=a[m2];
	}
	if(move<m1){
		ret=min(ret, sol(left&(~(1<<m1))&(~(1<<m2))|(1<<move),
			 right|(1<<m1)|(1<<m2)&(~(1<<move)))+a[m2]+a[move]);
		ret=min(ret, sol(left&(~(1<<m1))&(~(1<<M1))|(1<<move),
			 right|(1<<m1)|(1<<M1)&(~(1<<move)))+a[M1]+a[move]);
	}
	else{
		ret=min(ret, sol(left&(~(1<<m2)), right|(1<<m2))+a[m2]+a[m1]);
		ret=min(ret, sol(left&(~(1<<M1)), right|(1<<M1))+a[M1]+a[m1]);
	}
	if(move!=N){
		ret=min(ret, sol(left&(~(1<<M1))&(~(1<<M2))|(1<<move),
			 right|(1<<M1)|(1<<M2)&(~(1<<move)))+a[M1]+a[move]);
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;++i)	cin>>a[i];
	sort(a, a+N);
	int ans=0;
	cout<<sol((1<<N)-1, 0)<<"\n";
	return 0;
}
