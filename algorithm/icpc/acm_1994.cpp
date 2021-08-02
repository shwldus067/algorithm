#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
vector<int> arr;
bool chk[2000][2000];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	arr.resize(N);
	for(int i=0;i<N;++i){
		cin>>arr[i];
	}
	sort(arr.begin(), arr.end());
	int pre=arr[0], cnt=1, ans=1;
	for(int i=1;i<N;++i){
		if(pre==arr[i])	cnt++;
		else{
			if(cnt>ans)	ans=cnt;
			pre=arr[i];
			cnt=1;
		}
	}
	if(cnt>ans)	ans=cnt;
	arr.erase(unique(arr.begin(), arr.end()), arr.end());
	N=arr.size();
	for(int i=0;i<N;++i){
		for(int j=i+1;j<N;++j){
			if(chk[i][j])	continue;
			chk[i][j]=true;
			int cnt=2;
			int diff=arr[j]-arr[i];
			int val=arr[j]+diff;
			int k=j;
			while(1){
				int idx=lower_bound(arr.begin(), arr.end(), val)-arr.begin();
				if(arr[idx]!=val)	break;
				chk[k][idx]=true;
				k=idx;
				val+=diff;
				cnt++;
			}
			if(cnt>ans)	ans=cnt;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
