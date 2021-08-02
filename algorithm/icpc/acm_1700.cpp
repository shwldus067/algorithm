#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, K, cnt=0, idx=0;
	cin>>N>>K;
	int arr[K];
	int plug[N]={0, };
	bool on[K+1]={false, };
	for(int i=0;i<K;i++)	cin>>arr[i];
	for(int i=0;i<K;i++){
		if(on[arr[i]])	continue;
		if(idx<N){
			on[arr[i]]=true;
			plug[idx]=arr[i];
			idx++;
			continue;
		}
		int x=0, off;
		for(int j=0;j<N;j++){
			int t=plug[j];
			int k=i+1;
			for(;k<K;k++){
				if(t==arr[k]){
					break;
				}
			}
			if(x<k){
				x=k;
				off=j;
			}
		}
		cnt++;
		on[plug[off]]=false;
		on[arr[i]]=true;
		plug[off]=arr[i];
	}
	cout<<cnt<<"\n";
	return 0;
}
