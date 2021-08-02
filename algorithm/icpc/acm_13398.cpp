#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	int A[n];
	for(int i=0;i<n;i++)	cin>>A[i];
	int res[n][2], ans;
	ans=res[0][0]=res[0][1]=A[0];
	for(int i=1;i<n;i++){
		res[i][0]=max(res[i-1][0]+A[i], A[i]);
		res[i][1]=max(res[i-1][0], res[i-1][1]+A[i]);
		ans=max(ans, max(res[i][0], res[i][1]));
	}
	cout<<ans<<"\n";
	return 0;
}
