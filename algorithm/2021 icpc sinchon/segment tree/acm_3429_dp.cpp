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
		for(int i=1;i<=N;++i)	dp[i]=2e9;	//dp[i]:��� �����ϴ� ���� ������ i��° �迭���� �ּڰ� 
		int p=0, ans=1, M=0;	//p:�����ϴ� ���� ������ ���� �ε���, M:�����ϴ� ���� ������ �ִ� ���� 
		for(int i=1;i<=N;++i){
			if(arr[i]>arr[i-1])	continue;
			int n=i-p;	//p���� i-1���� ����, �����ϴ� ���� ���� ���� 
			if(n>ans)	ans=n;
			int j=p-1;	//dp�� update�ϱ� ���� ���� 
			for(;p<i;++p){	//
				int l=1, r=M, k=0;	//p��° �տ��� ���� �� �ִ� �����ϴ� ���� ������ �ִ� ���̸� ã�� 
				while(l<=r){	//arr[p]�� ���� dp������ ū ���� ū m���� ã�� 
					int m=(l+r)/2;
					if(dp[m]<arr[p])	l=m+1, k=m;	//k:p��° �� Ÿ���� ���ּ� p��°�� ����Ǿ� �����ϴ� ���� ������ ���� �� �ִ� ������ �ִ� ���� 
					else	r=m-1;
				}
				int tmp=k+i-p;	//p����k�� + p~i-1��°����->Ÿ���� ���ּ� ���� �� �ִ� ���� �ִ� ���� 
				if(tmp>ans)	ans=tmp;
			}
			if(n>M)	M=n;	//������ �ִ� ���� update 
			//�����ϴ� ���� ������ p ~ i-1��° �迭�� ���� �ܰ迡�� ã�� �� �ֵ��� update
			for(int t=1;t<=n;++t)	dp[t]=min(dp[t], arr[j+t]);	 //�ִ��� �� ������ ã�� ���ؼ� p��° ������ ���� �迭���� ���� ã�������� �ּҰ��� ���� 
		}
		cout<<ans<<"\n";
	}
	return 0;
}
