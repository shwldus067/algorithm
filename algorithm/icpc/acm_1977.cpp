#include<iostream>
#include<math.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int M, N, min, max, sum;
	cin>>M>>N;
	min=ceil(sqrt(M));
	max=floor(sqrt(N));
	if(min*min>N){
		cout<<-1<<"\n";
		return 0;
	}
	sum=(max*(max+1)*(2*max+1)/6)-((min-1)*min*(2*min-1)/6);
	cout<<sum<<"\n"<<min*min<<"\n";
	return 0;
}
