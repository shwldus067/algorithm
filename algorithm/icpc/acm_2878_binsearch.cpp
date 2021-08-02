#include<iostream>
using namespace std;
typedef unsigned long long ull;
int N, M, arr[100000];
ull bin(ull x){	//�ִ� x���� ���� �� ���� �Ǵ� ������ ��
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
	ull ans=0, l=0, r=0, sum=0;	//l:������ �� ���� �ּ�, r:������ �� �ִ� �ִ� 
	cin>>M>>N;
	for(int i=0;i<N;++i){
		cin>>arr[i];
		if(r<arr[i])	r=arr[i];
		sum+=arr[i];
	}
	ull q=sum-M, m, t;	//������ �� ���� ������ ��
	while(l+1<r){
		m=(l+r)/2;
		t=bin(m);
		if(t<q)	l=m;	//�� ���� ������ ������ �� �ִ���
		else	r=m;
	}
	t=q-bin(l);	//�ִ� l���� ���� �� ���� �� �ִ� ���� 
	while(t--){
		ans+=l+l+1; //(l+1)*(l+1)-l*l; t���� l+1���� ���� 
	}
	for(int i=0;i<N;++i){
		if(arr[i]<l)	ans+=(ull)arr[i]*(ull)arr[i];
		else	ans+=l*l;
	}
	cout<<ans<<"\n";
	return 0;
}
