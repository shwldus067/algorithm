#include<iostream>
using namespace std;
int N, arr[2][20][20];
int chk(int s[2], int e[2]){
	int cnt[3]={0, };
	for(int i=s[0];i<=e[0];++i)
		for(int j=s[1];j<=e[1];++j)
			++cnt[arr[0][i][j]];
	if(cnt[2]==0)	return 0;
	if(cnt[2]==1){
		if(cnt[1]==0)	return 1;
		else return 0;
	}
	if(cnt[1]==0)	return 0;
	return 2;
}
int cut(int s[2], int e[2], bool d){
	int t=chk(s, e);
	if(t==0 || t==1)	return t;
	int ret=0, first, second, ns[2], ne[2];
	for(int i=s[!d]+1;i<e[!d];++i){
		bool p=false;
		for(int j=s[d];j<=e[d];++j){
			if(arr[!d][i][j]==2){
				p=false;
				break;
			}
			if(arr[!d][i][j]==1)	p=true;
		}
		if(!p)	continue;
		if(d){
			ns[0]=i+1, ns[1]=s[1], ne[0]=i-1, ne[1]=e[1];
		}
		else{
			ns[0]=s[0], ns[1]=i+1, ne[0]=e[0], ne[1]=i-1;
		}
		if((first=cut(s, ne, !d))==0)	continue;
		if((second=cut(ns, e, !d))==0)	continue;
		ret+=first*second;
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	int tmp;
	for(int i=0;i<N;++i)
		for(int j=0;j<N;++j){
			cin>>tmp;
			arr[0][i][j]=arr[1][j][i]=tmp;
		}
	int s[2]={0, 0}, e[2]={N-1, N-1};
	int ans=cut(s, e, 0)+cut(s, e, 1);
	if(ans)	cout<<ans<<"\n";
	else	cout<<"-1\n";
	return 0;
}
