#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int arr[40];
int N, S;
long long res=0;
vector<int> left_v;
vector<int> right_v;
void left_f(int sum, int x){
	if(x==N/2){
		left_v.push_back(sum);
		return;
	}
	left_f(sum+arr[x], x+1);
	left_f(sum, x+1);
}
void right_f(int sum, int x){
	if(x==N){
		right_v.push_back(sum);
		return;
	}
	right_f(sum+arr[x], x+1);
	right_f(sum, x+1);
}
void f(int lx, int rx){
	if(lx>=left_v.size() || rx<0)	return;
	if(left_v[lx]+right_v[rx]==S){
		long long lc=0, rc=0;
		int t=lx;
		while(lx<left_v.size() && left_v[t]==left_v[lx]){
			lc++;
			lx++;
		}
		t=rx;
		while(0<=rx && right_v[t]==right_v[rx]){
			rc++;
			rx--;
		}
		res+=lc*rc;
		f(lx, rx);
	}
	else if(left_v[lx]+right_v[rx]<S){
		f(lx+1, rx);
	}
	else if(left_v[lx]+right_v[rx]>S){
		f(lx, rx-1);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>N>>S;
	int sum=0;
	for(int i=0;i<N;i++){
		cin>>arr[i];
		sum+=arr[i];
	}
	left_f(0, 0);
	right_f(0, N/2);
	sort(left_v.begin(), left_v.end());
	sort(right_v.begin(), right_v.end());
	f(0, right_v.size()-1);
	if(S==0){
		res--;
	}
	cout<<res<<"\n";
	return 0;
}
