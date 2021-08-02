#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, M;
vector<int> A;
int binsearch(int low, int high, int target){
	if(low>high)	return 0;
	else{
		int mid=(low+high)/2;
		if(A[mid]==target)	return 1;
		else if(A[mid]>target)	return binsearch(low, mid-1, target);
		else	return binsearch(mid+1, high, target);
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int num;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>num;
		A.push_back(num);
	}
	sort(A.begin(), A.end());
	cin>>M;
	for(int i=0;i<M;i++){
		cin>>num;
		cout<<binsearch(0, N-1, num)<<"\n";
	}
	return 0;
}
