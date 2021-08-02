#include<iostream>
using namespace std;
int N, v[1000];
char arr[1001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	cin>>arr;
	int cnt=1, ans=0;
	for(int i=0;i<N;++i){
		int f=0, c=i;
		while(1){
			if(v[c]!=0){
				if(v[c]==cnt)	f=1;
				break;
			}
			v[c]=cnt;
			if(arr[c]=='E')	++c;
			else	--c;
		}
		if(f)	++ans;
		++cnt;
	}
	cout<<ans<<"\n";
	return 0;
}
