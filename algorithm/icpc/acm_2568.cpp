#include<iostream>
#include<algorithm>
using namespace std;
int N, res[100005], cnt=1, p[100005]={-1, };
pair<int, int> arr[100000];
bool chk[100000];
bool cmp(int a, int b){
	return arr[a].second<arr[b].second;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	if(N==0){
		cout<<"0\n";
		return 0;
	}
	for(int i=0;i<N;++i){
		cin>>arr[i].first>>arr[i].second;
	}
	sort(arr, arr+N);
	res[0]=0;
	for(int i=1;i<N;++i){
		if(arr[res[cnt-1]].second<arr[i].second){
			p[i]=res[cnt-1];
			res[cnt++]=i;
		}
		else{
			int t=lower_bound(res, res+cnt, i, cmp)-res;
			p[i]=t ? res[t-1]:-1;
			res[t]=i;
		}
	}
	cout<<N-cnt<<"\n";
	for(int x=res[cnt-1];x!=-1;x=p[x]){
		chk[x]=true;
	}
	for(int i=0;i<N;++i){
		if(!chk[i])	cout<<arr[i].first<<"\n";
	}
	return 0;
}
