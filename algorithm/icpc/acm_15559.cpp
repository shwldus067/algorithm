#include<iostream>
using namespace std;
int N, M, v[1000][1000];
char arr[1001][1001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=0;i<N;++i)	cin>>arr[i];
	int cnt=1, ans=0;
	for(int i=0;i<N;++i)for(int j=0;j<M;++j){
		int f=0, r=i, c=j;
		while(1){
			if(v[r][c]!=0){
				if(v[r][c]==cnt)	f=1;
				break;
			}
			v[r][c]=cnt;
			if(arr[r][c]=='E')	++c;
			else if(arr[r][c]=='W')	--c;
			else if(arr[r][c]=='N')	--r;
			else	++r;
		}
		if(f)	++ans;
		++cnt;
	}
	cout<<ans<<"\n";
	return 0;
}
