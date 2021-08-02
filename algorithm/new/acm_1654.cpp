#include<iostream>
using namespace std;

int main(){
	int K, N;
	int tmp, max, cnt, i, j;
	long long sum=0, mid, left, right;
	cin>>K>>N;
	int len[K];
	for(i=0;i<K;i++){
		cin>>tmp;
		sum+=tmp;
		len[i]=tmp;
	}
	max=0;
	left=1;
	right=sum/N;
	while(left<=right){
		mid=(left+right)/2;
		cnt=0;
		for(j=0;j<K;j++){
			cnt+=len[j]/mid;
		}
		if(cnt>=N){
			left=mid+1;
			if(mid>max){
				max=mid;
			}
		}
		else{
			right=mid-1;
		}
	}
	
	cout<<max;
	return 0;
}
