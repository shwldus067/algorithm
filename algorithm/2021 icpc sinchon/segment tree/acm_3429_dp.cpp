#include<iostream>
using namespace std;
int arr[200001], dp[200001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int Z, N;
	cin>>Z;
	while(Z--){
		cin>>N;
		for(int i=0;i<N;++i)	cin>>arr[i];
		arr[N]=0;
		for(int i=1;i<=N;++i)	dp[i]=2e9;	//dp[i]:모든 연속하는 증가 수열의 i번째 배열값의 최솟값 
		int p=0, ans=1, M=0;	//p:연속하는 증가 수열의 시작 인덱스, M:연속하는 증가 수열의 최대 길이 
		for(int i=1;i<=N;++i){
			if(arr[i]>arr[i-1])	continue;
			int n=i-p;	//p부터 i-1까지 개수, 연속하는 증가 수열 길이 
			if(n>ans)	ans=n;
			int j=p-1;	//dp값 update하기 위해 저장 
			for(;p<i;++p){	//
				int l=1, r=M, k=0;	//p번째 앞에서 만들 수 있는 연속하는 증가 수열의 최대 길이를 찾음 
				while(l<=r){	//arr[p]의 값이 dp값보다 큰 가장 큰 m값을 찾음 
					int m=(l+r)/2;
					if(dp[m]<arr[p])	l=m+1, k=m;	//k:p번째 앞 타워를 없애서 p번째에 연결되어 연속하는 증가 수열을 만들 수 있는 수열의 최대 길이 
					else	r=m-1;
				}
				int tmp=k+i-p;	//p앞의k개 + p~i-1번째까지->타워를 없애서 만들 수 있는 수열 최대 길이 
				if(tmp>ans)	ans=tmp;
			}
			if(n>M)	M=n;	//수열의 최대 길이 update 
			//연속하는 증가 수열인 p ~ i-1번째 배열을 다음 단계에서 찾을 수 있도록 update
			for(int t=1;t<=n;++t)	dp[t]=min(dp[t], arr[j+t]);	 //최대한 긴 수열을 찾기 위해서 p번째 값보다 작은 배열값이 많이 찾아지도록 최소값을 저장 
		}
		cout<<ans<<"\n";
	}
	return 0;
}
