#include<iostream>
using namespace std;
int N, arr[20], res=0;
void f(int i){
	if(i==N){
		int sum=0;
		for(int c=0;c<N;c++){
			int cnt=0;
			for(int r=0;r<N;r++){
				if(arr[r]&(1<<c)){
					cnt++;
				}
			}
			if(cnt>N-cnt)	sum+=N-cnt;
			else	sum+=cnt;
			if(sum>=res)	return;
		}
		if(res>sum)	res=sum;
	}
	else{
		arr[i]=~arr[i];
		f(i+1);
		arr[i]=~arr[i];
		f(i+1);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	char t;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin>>t;
			if(t=='T'){
				arr[i]|=(1<<j);
				res++;
			}
		}
	}
	f(0);
	cout<<res<<"\n";
	return 0;
}
