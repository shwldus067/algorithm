#include<iostream>
using namespace std;
typedef unsigned long long ull;
int N, M, arr[100000];
ull bin(ull x){	//최대 x개씩 남을 때 남게 되는 사탕의 합
	ull ret=0;
	for(int i=0;i<N;++i){
		if(arr[i]>x)	ret+=x;
		else	ret+=arr[i];
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ull ans=0, l=0, r=0, sum=0;	//l:나눠줄 수 없는 최소, r:나눠줄 수 있는 최대 
	cin>>M>>N;
	for(int i=0;i<N;++i){
		cin>>arr[i];
		if(r<arr[i])	r=arr[i];
		sum+=arr[i];
	}
	ull q=sum-M, m, t;	//나눠줄 수 없는 사탕의 수
	while(l+1<r){
		m=(l+r)/2;
		t=bin(m);
		if(t<q)	l=m;	//더 많은 사탕을 나눠줄 수 있는지
		else	r=m;
	}
	t=q-bin(l);	//최대 l개씩 남고 더 남길 수 있는 개수 
	while(t--){
		ans+=l+l+1; //(l+1)*(l+1)-l*l; t개에 l+1개씩 남음 
	}
	for(int i=0;i<N;++i){
		if(arr[i]<l)	ans+=(ull)arr[i]*(ull)arr[i];
		else	ans+=l*l;
	}
	cout<<ans<<"\n";
	return 0;
}
