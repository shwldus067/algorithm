#include<iostream>
using namespace std;
int N, ans, cnt;
int f[1000001], arr[1000001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=N-1;i>=0;--i)	cin>>arr[i];
	for(int i=1, j=0;i<N;++i){
		while(j && arr[i]!=arr[j]){
			j=f[j-1];
		}
		if(arr[i]==arr[j]){
			f[i]=++j;
			if(ans<f[i]){
				ans=f[i];
				cnt=1;
			}
			else if(ans==f[i]){
				cnt++;
			}
		}
	}
	if(!ans)	cout<<-1;
	else cout<<ans<<" "<<cnt;
	return 0;
}
