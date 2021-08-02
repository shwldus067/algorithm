#include<iostream>
#include<algorithm>
using namespace std;
int N, arr[1000000], p[1000000]={-1, }, idx;
int A[1000000], order[1000000];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	cin>>arr[idx++];
	A[0]=arr[0];
	for(int i=1;i<N;++i){
		int t;
		cin>>t;
		A[i]=t;
		if(arr[idx-1]<t){
			order[idx]=i;
			p[i]=order[idx-1];
			arr[idx++]=t;
		}
		else{
			int *iter;
			iter=lower_bound(arr, arr+idx, t);
			*iter=t;
			int x=iter-arr;
			order[x]=i;
			if(x==0)	p[i]=-1;
			else	p[i]=order[x-1];
		}
	}
	cout<<idx<<"\n";
	int ans[idx];
	for(int i=order[idx-1], j=idx-1;i>=0;i=p[i], --j){
		ans[j]=A[i];
	}
	for(int i=0;i<idx;++i)	cout<<ans[i]<<" ";
	return 0;
}
